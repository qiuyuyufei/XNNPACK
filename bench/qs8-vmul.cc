// Copyright 2021 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <algorithm>
#include <cmath>
#include <functional>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>
#include "bench/utils.h"

#include <xnnpack/AlignedAllocator.h>
#include <xnnpack/common.h>
#include <xnnpack/params.h>
#include <xnnpack/params-init.h>
#include <xnnpack/vmul.h>


static void qs8_vmul(
  benchmark::State& state,
  xnn_qs8_vmul_minmax_ukernel_function vmul,
  xnn_init_qs8_mul_minmax_params_fn init_params,
  benchmark::utils::IsaCheckFunction isa_check = nullptr)
{
  if (isa_check && !isa_check(state)) {
    return;
  }

  const size_t num_elements = state.range(0);

  std::random_device random_device;
  auto rng = std::mt19937(random_device());
  auto i8rng = std::bind(
    std::uniform_int_distribution<int32_t>(std::numeric_limits<int8_t>::min(), std::numeric_limits<int8_t>::max()),
    std::ref(rng));

  std::vector<int8_t, AlignedAllocator<int8_t, 64>> a(num_elements);
  std::vector<int8_t, AlignedAllocator<int8_t, 64>> b(num_elements);
  std::vector<int8_t, AlignedAllocator<int8_t, 64>> product(num_elements);
  std::generate(a.begin(), a.end(), std::ref(i8rng));
  std::generate(b.begin(), b.end(), std::ref(i8rng));

  union xnn_qs8_mul_minmax_params params;
  init_params(&params,
    1 /* a zero point */, 1 /* b zero point */, 1 /* output zero point */,
    0.75f /* product-output scale */,
    std::numeric_limits<int8_t>::min() + 1, std::numeric_limits<int8_t>::max() - 1);
  for (auto _ : state) {
    vmul(num_elements * sizeof(int8_t), a.data(), b.data(), product.data(), &params);
  }

  const uint64_t cpu_frequency = benchmark::utils::GetCurrentCpuFrequency();
  if (cpu_frequency != 0) {
    state.counters["cpufreq"] = cpu_frequency;
  }

  const size_t num_elements_per_iteration = num_elements;
  state.counters["num_elements"] =
    benchmark::Counter(uint64_t(state.iterations()) * num_elements_per_iteration, benchmark::Counter::kIsRate);

  const size_t bytes_per_iteration = 3 * num_elements * sizeof(int8_t);
  state.counters["bytes"] =
    benchmark::Counter(uint64_t(state.iterations()) * bytes_per_iteration, benchmark::Counter::kIsRate);
}

#if XNN_ARCH_ARM || XNN_ARCH_ARM64
  BENCHMARK_CAPTURE(qs8_vmul, neonv8_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neonv8_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_neonv8_params,
                    benchmark::utils::CheckNEONV8)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, neonv8_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neonv8_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_neonv8_params,
                    benchmark::utils::CheckNEONV8)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(qs8_vmul, neonv8_ld128_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neonv8_ld128_x16,
                    xnn_init_qs8_mul_minmax_fp32_neonv8_params,
                    benchmark::utils::CheckNEONV8)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(qs8_vmul, neon_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neon_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_neon_params,
                    benchmark::utils::CheckNEON)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, neon_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neon_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_neon_params,
                    benchmark::utils::CheckNEON)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(qs8_vmul, neon_ld128_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__neon_ld128_x16,
                    xnn_init_qs8_mul_minmax_fp32_neon_params,
                    benchmark::utils::CheckNEON)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
#endif  // XNN_ARCH_ARM || XNN_ARCH_ARM64

#if XNN_ARCH_X86 || XNN_ARCH_X86_64
  BENCHMARK_CAPTURE(qs8_vmul, avx_mul16_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__avx_mul16_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_sse4_params,
                    benchmark::utils::CheckAVX)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, avx_mul16_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__avx_mul16_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_sse4_params,
                    benchmark::utils::CheckAVX)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(qs8_vmul, sse41_mul16_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__sse41_mul16_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_sse4_params,
                    benchmark::utils::CheckSSE41)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, sse41_mul16_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__sse41_mul16_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_sse4_params,
                    benchmark::utils::CheckSSE41)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();

  BENCHMARK_CAPTURE(qs8_vmul, sse2_mul16_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__sse2_mul16_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_sse2_params)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, sse2_mul16_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__sse2_mul16_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_sse2_params)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
#endif  // XNN_ARCH_X86 || XNN_ARCH_X86_64

#if XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD
  BENCHMARK_CAPTURE(qs8_vmul, wasmsimd_mul32_ld64_x8,
                    xnn_qs8_vmul_minmax_fp32_ukernel__wasmsimd_mul32_ld64_x8,
                    xnn_init_qs8_mul_minmax_fp32_wasmsimd_params)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
  BENCHMARK_CAPTURE(qs8_vmul, wasmsimd_mul32_ld64_x16,
                    xnn_qs8_vmul_minmax_fp32_ukernel__wasmsimd_mul32_ld64_x16,
                    xnn_init_qs8_mul_minmax_fp32_wasmsimd_params)
    ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
    ->UseRealTime();
#endif  // XNN_ARCH_WASMSIMD || XNN_ARCH_WASMRELAXEDSIMD

BENCHMARK_CAPTURE(qs8_vmul, scalar_x1,
                  xnn_qs8_vmul_minmax_fp32_ukernel__scalar_x1,
                  xnn_init_qs8_mul_minmax_fp32_scalar_params)
  ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
  ->UseRealTime();
BENCHMARK_CAPTURE(qs8_vmul, scalar_x2,
                  xnn_qs8_vmul_minmax_fp32_ukernel__scalar_x2,
                  xnn_init_qs8_mul_minmax_fp32_scalar_params)
  ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
  ->UseRealTime();
BENCHMARK_CAPTURE(qs8_vmul, scalar_x4,
                  xnn_qs8_vmul_minmax_fp32_ukernel__scalar_x4,
                  xnn_init_qs8_mul_minmax_fp32_scalar_params)
  ->Apply(benchmark::utils::BinaryElementwiseParameters<int8_t, int8_t>)
  ->UseRealTime();

#ifndef XNNPACK_BENCHMARK_NO_MAIN
BENCHMARK_MAIN();
#endif
