cmake_minimum_required(VERSION 3.5)

project(riscv_transform)

INCLUDE_DIRECTORIES(${DSP}/Include)

add_library(riscv_transform STATIC)

target_sources(riscv_transform PRIVATE riscv_bitreversal2.c)
target_sources(riscv_transform PRIVATE riscv_bitreversal.c)
target_sources(riscv_transform PRIVATE riscv_cfft_f32.c)
target_sources(riscv_transform PRIVATE riscv_cfft_q15.c)
target_sources(riscv_transform PRIVATE riscv_cfft_q31.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_f32.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_init_f32.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_init_q15.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_init_q31.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_q15.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix2_q31.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_f32.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_init_f32.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_init_q15.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_init_q31.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_q15.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix4_q31.c)
target_sources(riscv_transform PRIVATE riscv_cfft_radix8_f32.c)
target_sources(riscv_transform PRIVATE riscv_dct4_f32.c)
target_sources(riscv_transform PRIVATE riscv_dct4_init_f32.c)
target_sources(riscv_transform PRIVATE riscv_dct4_init_q15.c)
target_sources(riscv_transform PRIVATE riscv_dct4_init_q31.c)
target_sources(riscv_transform PRIVATE riscv_dct4_q15.c)
target_sources(riscv_transform PRIVATE riscv_dct4_q31.c)
target_sources(riscv_transform PRIVATE riscv_rfft_f32.c)
target_sources(riscv_transform PRIVATE riscv_rfft_fast_f32.c)
target_sources(riscv_transform PRIVATE riscv_rfft_fast_init_f32.c)
target_sources(riscv_transform PRIVATE riscv_rfft_init_f32.c)
target_sources(riscv_transform PRIVATE riscv_rfft_init_q15.c)
target_sources(riscv_transform PRIVATE riscv_rfft_init_q31.c)
target_sources(riscv_transform PRIVATE riscv_rfft_q15.c)
target_sources(riscv_transform PRIVATE riscv_rfft_q31.c)
