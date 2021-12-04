cmake_minimum_required(VERSION 3.21)

project(solve)

# 添加源文件和头文件路径
file(GLOB_RECURSE SRC ${PROJECT_SOURCE_DIR}/source/*.c)
set(INCLUDE_DIRECTORIES ${PROJECT_SOURCE_DIR}/include/)

# 获取petsc库路径
set(ENV{PKG_CONFIG_PATH} ~/workSpace/programs/petsc/arch-ci-linux-intel-mkl-single/lib/pkgconfig/)
find_package(PkgConfig)
pkg_search_module(PETSCLIB REQUIRED petsc)

# 头文件路径
include_directories(${INCLUDE_DIRECTORIES})
include_directories(${PETSCLIB_INCLUDE_DIRS})

# 打印
message("=====${PETSCLIB_INCLUDE_DIRS}")
message("=====${PETSCLIB_LIBRARY_DIRS}")
message("=====${PETSCLIB_LIBRARIES}")

# 添加源文件
add_executable(${PROJECT_NAME} ${SRC})

# 链接库
target_link_libraries(${PROJECT_NAME} ${PETSCLIB_LIBRARY_DIRS}/libpetsc.so)
target_link_libraries(${PROJECT_NAME} /opt/intel/oneapi/mpi/2021.3.0//lib/release/libmpi.so.12)
