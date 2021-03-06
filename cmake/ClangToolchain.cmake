set(CMAKE_SYSTEM_PROCESSOR ${OS_ARCH})
set(triple x86_64-pc-linux-elf)
set(CMAKE_C_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_TARGET ${triple})
set(CMAKE_CXX_COMPILER_EXTERNAL_TOOLCHAIN ${CLANG_TOOLCHAIN_SYSROOT})
set(CMAKE_C_COMPILER_EXTERNAL_TOOLCHAIN ${CLANG_TOOLCHAIN_SYSROOT})
list(APPEND KERNEL_LINK_FLAGS -fuse-ld=lld)
# Fun GNU conventions
include_directories(SYSTEM 
   ${CLANG_TOOLCHAIN_SYSROOT}/include
   ${CLANG_TOOLCHAIN_SYSROOT}/${CLANG_CXX_TOOLCHAIN_PREFIX}/include/
   ${CLANG_TOOLCHAIN_SYSROOT}/${CLANG_CXX_TOOLCHAIN_PREFIX}/include/c++/${CLANG_CXX_TOOLCHAIN_VERSION}
   ${CLANG_TOOLCHAIN_SYSROOT}/${CLANG_CXX_TOOLCHAIN_PREFIX}/include/c++/${CLANG_CXX_TOOLCHAIN_VERSION}/${CLANG_CXX_TOOLCHAIN_PREFIX}
)
link_directories(SYSTEM
   ${CLANG_TOOLCHAIN_SYSROOT}/lib
)