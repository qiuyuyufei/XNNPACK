// Copyright (c) Facebook, Inc. and its affiliates.
// All rights reserved.
//
// Copyright 2019 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#pragma once

#include <stddef.h>
#include <stdint.h>

#include <xnnpack/common.h>
#include <xnnpack/microparams.h>

#ifdef __cplusplus
extern "C" {
#endif


#define DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                 \
    size_t channels,                                         \
    size_t output_width,                                     \
    const float** input,                                     \
    const float* weights,                                    \
    float* output,                                           \
    intptr_t input_stride,                                   \
    size_t output_increment,                                 \
    size_t input_offset,                                     \
    const float* zero,                                       \
    const union xnn_f32_default_params* params);

#define DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const float** input,                                            \
    const float* weights,                                           \
    float* output,                                                  \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const float* zero,                                              \
    const union xnn_f32_minmax_params* params);

#define DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                   \
    size_t channels,                                           \
    size_t output_width,                                       \
    const float** input,                                       \
    const float* weights,                                      \
    float* output,                                             \
    intptr_t input_stride,                                     \
    size_t output_increment,                                   \
    size_t input_offset,                                       \
    const float* zero,                                         \
    size_t kernel_size,                                        \
    float* buffer,                                             \
    const union xnn_f32_default_params* params);

#define DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                          \
    size_t channels,                                                  \
    size_t output_width,                                              \
    const float** input,                                              \
    const float* weights,                                             \
    float* output,                                                    \
    intptr_t input_stride,                                            \
    size_t output_increment,                                          \
    size_t input_offset,                                              \
    const float* zero,                                                \
    size_t kernel_size,                                               \
    float* buffer,                                                    \
    const union xnn_f32_minmax_params* params);

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c4s4r__sse_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l16c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l16c4s4r__sse_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l16c4s4r__sse)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l16c4s4r__sse_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l8c4s4r__sse_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c8s4r__avx_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c8s4r__avx_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c8s4r__avx_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l16c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l16c8s4r__avx_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c8s4r__avx_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l16c8s4r__avx)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l16c8s4r__avx_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c8s4r__fma3_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c8s4r__fma3_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l32c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l32c8s4r__fma3_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l8c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l8c8s4r__fma3_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l16c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l16c8s4r__fma3_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l32c8s4r__fma3)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_7f6m6l32c8s4r__fma3_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c16s4r__avx512f)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l16c16s4r__avx512f_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__neonfma_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__neonfma_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__neonfma_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__neonfma_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__neonfma_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__neonfma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__neonfma_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__neon_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l8c4s4r__neon_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l4c4s4r__neon_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l8c4s4r__neon_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l4c4s4r__neon_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__neon)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l8c4s4r__neon_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l1c1s1r__wasm)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l1c1s1r__wasm_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l1c1s1r__wasm)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l1c1s1r__wasm_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l1c1s1r__wasm)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l1c1s1r__wasm_acc2)

DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l4c4s4r__wasmsimd)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l4c4s4r__wasmsimd_acc2)

DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd_fma_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmsimd_arm)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmsimd_arm_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmsimd_x86)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmsimd_x86_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l4c4s4r__wasmrelaxedsimd_fma_acc2)

DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_2f2m2l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_2f2m2l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_2f2m2l4c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_2f2m2l4c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_5f5m5l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_6f6m7l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_6f6m7l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_8f8m9l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_8f8m9l1c1s1r__scalar_acc2)

DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_2f2m2l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_2f2m2l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_2f2m2l4c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_2f2m2l4c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_5f5m5l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_6f6m7l1c1s1r__scalar_acc2)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l1c1s1r__scalar)
DECLARE_F32_DWCONV_MULTIPASS_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_8f8m9l1c1s1r__scalar_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__avx512f_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p16c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p32c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p32c__avx512f_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__avx512f_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p16c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p32c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p32c__avx512f_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__asm_aarch64_neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__asm_aarch64_neonfma_cortex_a55)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__avx512f_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p16c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p32c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p32c__avx512f_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__sse)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__sse_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__avx)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__avx_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__avx512f_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__fma3)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__fma3_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__neon)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__neon_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__neonfma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p16c__neonfma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p32c__avx512f)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p32c__avx512f_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p4c__wasmsimd)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p8c__wasmsimd)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p4c__wasmsimd_x86_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p8c__wasmsimd_x86_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p4c__wasmsimd)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p8c__wasmsimd)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p4c__wasmsimd_x86_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p8c__wasmsimd_x86_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p4c__wasmsimd)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p4c__wasmsimd_acc2)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p8c__wasmsimd)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p8c__wasmsimd_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p4c__wasmsimd_x86_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p8c__wasmsimd_x86_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p4c__wasmsimd)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p8c__wasmsimd)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p4c__wasmsimd_x86_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_fma)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmrelaxedsimd_fma_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_arm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_arm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_x86)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p8c__wasmsimd_x86_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p1c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p1c__wasm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p2c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p2c__wasm_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p1c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p1c__wasm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p2c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p2c__wasm_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p1c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p1c__wasm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p2c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p2c__wasm_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p1c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p1c__wasm_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p2c__wasm)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p2c__wasm_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p1c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p1c__scalar_acc2)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p2c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_3p2c__scalar_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p1c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p1c__scalar_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p2c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_3p2c__scalar_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p1c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p1c__scalar_acc2)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p2c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_4p2c__scalar_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p1c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p1c__scalar_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p2c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_4p2c__scalar_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p1c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p1c__scalar_acc2)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p2c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_9p2c__scalar_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p1c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p1c__scalar_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p2c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_9p2c__scalar_acc2)

DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p1c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p1c__scalar_acc2)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p2c__scalar)
DECLARE_F32_DWCONV_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_ukernel_25p2c__scalar_acc2)

DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p1c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p1c__scalar_acc2)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p2c__scalar)
DECLARE_F32_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f32_dwconv_minmax_ukernel_25p2c__scalar_acc2)


#define DECLARE_F16_DWCONV_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                 \
    size_t channels,                                         \
    size_t output_width,                                     \
    const void** input,                                      \
    const void* weights,                                     \
    void* output,                                            \
    intptr_t input_stride,                                   \
    size_t output_increment,                                 \
    size_t input_offset,                                     \
    const void* zero,                                        \
    const union xnn_f16_default_params* params);

#define DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const void** input,                                             \
    const void* weights,                                            \
    void* output,                                                   \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const void* zero,                                               \
    const union xnn_f16_minmax_params* params);

#define DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const void** input,                                             \
    const void* weights,                                            \
    void* output,                                                   \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const void* zero,                                               \
    size_t kernel_size,                                             \
    void* buffer,                                                  \
    const union xnn_f16_minmax_params* params);

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l8c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l8c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l16c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l16c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l32c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l32c8s4r__neonfp16arith_acc2)

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l8c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l8c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l16c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l16c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l32c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l32c8s4r__neonfp16arith_acc2)

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l8c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l8c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l16c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l16c8s4r__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l32c8s4r__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l32c8s4r__neonfp16arith_acc2)

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l8c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l8c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l16c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l16c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l32c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_5f5m5l32c8s4r__fma3_acc2)

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l8c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l8c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l16c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l16c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l32c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_6f6m7l32c8s4r__fma3_acc2)

DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l8c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l8c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l16c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l16c8s4r__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l32c8s4r__fma3)
DECLARE_F16_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_8f8m9l32c8s4r__fma3_acc2)

DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p8c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p8c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p16c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p16c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p32c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p32c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p8c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p8c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p16c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p16c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p32c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p32c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p8c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p8c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p16c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p16c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p32c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p32c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p8c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p8c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p16c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p16c__neonfp16arith_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p32c__neonfp16arith)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p32c__neonfp16arith_acc2)

DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p8c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p8c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p16c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p16c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p32c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_3p32c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p8c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p8c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p16c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p16c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p32c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_4p32c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p8c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p8c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p16c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p16c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p32c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_9p32c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p8c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p8c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p16c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p16c__fma3_acc2)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p32c__fma3)
DECLARE_F16_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_f16_dwconv_minmax_ukernel_25p32c__fma3_acc2)


#define DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const uint8_t** input,                                          \
    const void* weights,                                            \
    uint8_t* output,                                                \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const uint8_t* zero,                                            \
    const union xnn_qu8_conv_minmax_params* params);

#define DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                          \
    size_t channels,                                                  \
    size_t output_width,                                              \
    const uint8_t** input,                                            \
    const void* weights,                                              \
    uint8_t* output,                                                  \
    intptr_t input_stride,                                            \
    size_t output_increment,                                          \
    size_t input_offset,                                              \
    const uint8_t* zero,                                              \
    size_t kernel_size,                                               \
    uint32_t* buffer,                                                 \
    const union xnn_qu8_conv_minmax_params* params);

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p32c__neon_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__neonv8_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p32c__neonv8_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p8c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p32c__neon_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p8c__neon_mul8)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mul8)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p32c__neon_mul8)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__sse2_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__sse2_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__xop_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p32c__avx512skx_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p8c__wasmsimd_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p16c__wasmsimd_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p1c__wasm_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p2c__wasm_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p4c__wasm_fmagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p1c__scalar)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p2c__scalar)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_9p4c__scalar)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p1c__scalar_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p2c__scalar_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p4c__scalar_fmagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p1c__scalar_imagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p2c__scalar_imagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p4c__scalar_imagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p1c__scalar_lrintf)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p2c__scalar_lrintf)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_9p4c__scalar_lrintf)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p32c__neon_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__neonv8_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p32c__neonv8_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p8c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p32c__neon_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p8c__neon_mul8)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mul8)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_rndnu_ukernel_25p32c__neon_mul8)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__xop_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p32c__avx512skx_mul32)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p8c__wasmsimd_mul16)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p16c__wasmsimd_mul16)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p1c__wasm_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p2c__wasm_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p4c__wasm_fmagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p1c__scalar_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p2c__scalar_fmagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p4c__scalar_fmagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p1c__scalar_imagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p2c__scalar_imagic)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p4c__scalar_imagic)

DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p1c__scalar_lrintf)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p2c__scalar_lrintf)
DECLARE_QU8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_25p4c__scalar_lrintf)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse2_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse2_mul16)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse41_mul16)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse41_mul16)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__sse41_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__sse41_mul32)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__avx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__avx_mul32)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__xop_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__xop_mul32)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l32c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l32c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__avx2_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l32c8s8r__avx2_mul32)

DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s1r__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s1r__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s1r__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s1r__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s1r__avx512skx_mul32)
DECLARE_QU8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qu8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s1r__avx512skx_mul32)

#define DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const int8_t** input,                                           \
    const void* weights,                                            \
    int8_t* output,                                                 \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const int8_t* zero,                                             \
    const union xnn_qs8_conv_minmax_params* params);

#define DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                          \
    size_t channels,                                                  \
    size_t output_width,                                              \
    const int8_t** input,                                             \
    const void* weights,                                              \
    int8_t* output,                                                   \
    intptr_t input_stride,                                            \
    size_t output_increment,                                          \
    size_t input_offset,                                              \
    const int8_t* zero,                                               \
    size_t kernel_size,                                               \
    uint32_t* buffer,                                                 \
    const union xnn_qs8_conv_minmax_params* params);

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p8c__neon_mul8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mul8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mul8_ld128)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p8c__neon_mla8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mla8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mla8_ld128)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p8c__neon_mul8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mul8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mul8_ld128)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p8c__neon_mla8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mla8_ld64)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mla8_ld128)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__neon_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__neonv8_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__neonv8_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p8c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p16c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p32c__neon_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__sse2_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__sse2_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__xop_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__xop_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_vpmovsx)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_add16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__xop_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p32c__avx512skx_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__wasmsimd_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__wasmsimd_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p8c__wasmsimd_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p16c__wasmsimd_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p1c__wasm_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p2c__wasm_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p4c__wasm_fmagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p1c__scalar)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p2c__scalar)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_9p4c__scalar)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p1c__scalar_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p2c__scalar_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p4c__scalar_fmagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p1c__scalar_imagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p2c__scalar_imagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p4c__scalar_imagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p1c__scalar_lrintf)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p2c__scalar_lrintf)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_9p4c__scalar_lrintf)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__neon_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__neonv8_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__neonv8_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p8c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p16c__neon_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_rndnu_ukernel_25p32c__neon_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__sse2_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__sse2_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__xop_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__xop_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_vpmovsx)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_add16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__xop_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p32c__avx512skx_mul32)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__wasmsimd_mul16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__wasmsimd_mul16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p8c__wasmsimd_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p16c__wasmsimd_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p1c__wasm_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p2c__wasm_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p4c__wasm_fmagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p1c__scalar_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p2c__scalar_fmagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p4c__scalar_fmagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p1c__scalar_imagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p2c__scalar_imagic)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p4c__scalar_imagic)

DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p1c__scalar_lrintf)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p2c__scalar_lrintf)
DECLARE_QS8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_25p4c__scalar_lrintf)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse2_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse2_mul16)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse2_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse2_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse41_mul16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse41_mul16)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse41_mul16_add16)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse41_mul16_add16)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__sse41_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__sse41_mul32)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__avx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__avx_mul32)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__xop_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__xop_mul32)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_vpmovsx)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_add16_vpunpck)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l32c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l32c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__avx2_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l32c8s8r__avx2_mul32)

DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s1r__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s1r__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s1r__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s1r__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s1r__avx512skx_mul32)
DECLARE_QS8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qs8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s1r__avx512skx_mul32)

#define DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                        \
    size_t channels,                                                \
    size_t output_width,                                            \
    const int8_t** input,                                           \
    const void* weights,                                            \
    int8_t* output,                                                 \
    intptr_t input_stride,                                          \
    size_t output_increment,                                        \
    size_t input_offset,                                            \
    const int8_t* zero,                                             \
    const union xnn_qc8_conv_minmax_params* params);

#define DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                          \
    size_t channels,                                                  \
    size_t output_width,                                              \
    const int8_t** input,                                             \
    const void* weights,                                              \
    int8_t* output,                                                   \
    intptr_t input_stride,                                            \
    size_t output_increment,                                          \
    size_t input_offset,                                              \
    const int8_t* zero,                                               \
    size_t kernel_size,                                               \
    uint32_t* buffer,                                                 \
    const union xnn_qc8_conv_minmax_params* params);

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p8c__asm_aarch32_neonv8_mla8_cortex_a35)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__asm_aarch32_neonv8_mla8_cortex_a35)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p8c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__neon_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p8c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__neonv8_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_4p8c__neon_mla8_ld64)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neon_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neon_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neon_mul8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neon_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neonv8_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mul8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neon_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neon_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neon_mul8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neon_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neon_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neonv8_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mul8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mul8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mla8_ld64)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mla8_ld128)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neon_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neon_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__neon_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__neonv8_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__neonv8_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__neonv8_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neon_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neon_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__neon_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__neonv8_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__neonv8_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__neonv8_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p8c__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p8c__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__avx_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__xop_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p32c__avx512skx_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p16c__wasmsimd_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p1c__scalar_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p2c__scalar_imagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p2c__scalar_lrintf)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_3p2c__wasm_fmagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_4p2c__scalar_imagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__sse2_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__sse2_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__xop_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__xop_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_vpmovsx)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul16_add16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__sse41_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__xop_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__avx2_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p32c__avx512skx_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__wasmsimd_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__wasmsimd_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p8c__wasmsimd_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p16c__wasmsimd_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p1c__wasm_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p2c__wasm_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p4c__wasm_fmagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p1c__scalar_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p2c__scalar_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p4c__scalar_fmagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p1c__scalar_imagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p2c__scalar_imagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p4c__scalar_imagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p1c__scalar_lrintf)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p2c__scalar_lrintf)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_9p4c__scalar_lrintf)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__sse2_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__sse2_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__xop_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__xop_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_vpmovsx)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul16_add16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__sse41_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__xop_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__avx2_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p32c__avx512skx_mul32)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__wasmsimd_mul16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__wasmsimd_mul16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p8c__wasmsimd_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p16c__wasmsimd_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p1c__wasm_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p2c__wasm_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p4c__wasm_fmagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p1c__scalar_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p2c__scalar_fmagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p4c__scalar_fmagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p1c__scalar_imagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p2c__scalar_imagic)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p4c__scalar_imagic)

DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p1c__scalar_lrintf)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p2c__scalar_lrintf)
DECLARE_QC8_DWCONV_MINMAX_UNIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_25p4c__scalar_lrintf)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse2_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse2_mul16)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse2_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse2_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse41_mul16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse41_mul16)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__sse41_mul16_add16)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__sse41_mul16_add16)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__sse41_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__sse41_mul32)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__avx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__avx_mul32)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c4s4r__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c4s4r__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c4s4r__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c4s4r__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c4s4r__xop_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c4s4r__xop_mul32)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_vpmovsx)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_vpmovsx)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s16r__avx2_mul16_add16_vpunpck)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s16r__avx2_mul16_add16_vpunpck)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l8c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l32c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l8c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l32c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l8c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c8s8r__avx2_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l32c8s8r__avx2_mul32)

DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l16c16s1r__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_5f5m5l32c16s1r__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l16c16s1r__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_6f6m7l32c16s1r__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l16c16s1r__avx512skx_mul32)
DECLARE_QC8_DWCONV_MINMAX_MULTIPASS_UKERNEL_FUNCTION(xnn_qc8_dwconv_minmax_fp32_ukernel_8f8m9l32c16s1r__avx512skx_mul32)

#define DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                      \
    size_t input_height,                                          \
    size_t input_width,                                           \
    const float* input,                                           \
    const float* weights,                                         \
    const float* zero,                                            \
    float* output,                                                \
    uint32_t padding_top,                                         \
    const union xnn_f32_chw_params* params);

DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__neon_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__aarch64_neonfma_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_1x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_1x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_1x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_1x1_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_2x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_2x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_3x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_4x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_5x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__scalar_6x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__sse_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__ssse3_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_loadsplat_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_arm_splat_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_loadsplat_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3p1__wasmsimd_x86_splat_6x4)

DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__neon_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__aarch64_neonfma_6x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_1x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_1x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_1x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_1x1_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_2x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_2x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_3x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__scalar_4x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__sse_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_arm_splat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_3x3s2p1__wasmsimd_x86_splat_4x4)

DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__neon_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__aarch64_neonfma_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_1x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_1x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_1x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_1x1_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_1x1_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_2x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_2x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_2x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_3x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__scalar_3x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__sse_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_loadsplat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_arm_splat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_loadsplat_5x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_4x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_4x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5p2__wasmsimd_x86_splat_5x4)

DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__neon_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__aarch64_neonfma_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_1x1_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_2x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_2x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_2x1_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_3x1)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__scalar_3x1_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__sse_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_loadsplat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_arm_splat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_loadsplat_3x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_1x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_1x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_1x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_1x4_acc4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_1x4_acc5)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_2x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_2x4_acc2)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_2x4_acc3)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_3x4)
DECLARE_F32_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f32_dwconv2d_chw_ukernel_5x5s2p2__wasmsimd_x86_splat_3x4_acc2)


#define DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(fn_name) \
  XNN_INTERNAL void fn_name(                                      \
    size_t input_height,                                          \
    size_t input_width,                                           \
    const void* input,                                            \
    const void* weights,                                          \
    const void* zero,                                             \
    void* output,                                                 \
    uint32_t padding_top,                                         \
    const union xnn_f16_chw_params* params);

DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_1x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_1x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_1x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_1x8_acc4)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_2x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_2x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_3x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_4x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_5x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3p1__neonfp16arith_6x8)

DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_1x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_1x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_1x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_1x8_acc4)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_2x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_2x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_3x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_3x3s2p1__neonfp16arith_4x8)

DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_1x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_1x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_1x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_1x8_acc4)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_1x8_acc5)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_2x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_2x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_2x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_3x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_3x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_4x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_4x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5p2__neonfp16arith_5x8)

DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_1x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_1x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_1x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_1x8_acc4)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_1x8_acc5)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_2x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_2x8_acc2)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_2x8_acc3)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_3x8)
DECLARE_F16_DWCONV2D_CHW_MINMAX_UKERNEL_FUNCTION(xnn_f16_dwconv2d_chw_ukernel_5x5s2p2__neonfp16arith_3x8_acc2)

#ifdef __cplusplus
}  // extern "C"
#endif
