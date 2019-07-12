cmake_minimum_required(VERSION 3.14)

project(simde)

set(CMAKE_C_STANDARD 11)

add_library(${PROJECT_NAME}
        # simde/arm/neon/float32x2.h
        # simde/arm/neon/float32x4.h
        # simde/arm/neon/float64x1.h
        # simde/arm/neon/float64x2.h
        # simde/arm/neon/int16x4.h
        # simde/arm/neon/int16x8.h
        # simde/arm/neon/int32x2.h
        # simde/arm/neon/int32x4.h
        # simde/arm/neon/int64x1.h
        # simde/arm/neon/int64x2.h
        # simde/arm/neon/int8x16.h
        # simde/arm/neon/int8x8.h
        # simde/arm/neon/uint16x4.h
        # simde/arm/neon/uint16x8.h
        # simde/arm/neon/uint32x2.h
        # simde/arm/neon/uint32x4.h
        # simde/arm/neon/uint64x1.h
        # simde/arm/neon/uint64x2.h
        # simde/arm/neon/uint8x16.h
        # simde/arm/neon/uint8x8.h
        # simde/arm/neon.h
        # simde/simd-js/bool32x4.h
        # simde/simd-js/float32x4.h
        # simde/simd-js/int32x4.h
        # simde/simd-js/simd-js.h
        simde/x86/avx.h
        simde/x86/avx2.h
        simde/x86/mmx.h
        simde/x86/sse.h
        simde/x86/sse2.h
        simde/x86/sse3.h
        simde/x86/sse4.1.h
        simde/x86/sse4.2.h
        simde/x86/ssse3.h
        simde/hedley.h
        simde/simde-arch.h
        simde/simde-common.h
        simde/hw.c
        )

target_include_directories(${PROJECT_NAME} PUBLIC simde)
target_include_directories(${PROJECT_NAME} PUBLIC simde/x86)

# target_compile_options(${PROJECT_NAME} PUBLIC -std=c++11 -fpermissive -w -Wall )
