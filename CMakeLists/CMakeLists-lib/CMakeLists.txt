# 设置项目所需cmake的最低版本
cmake_minimum_required(VERSION 3.0.0)

# 项目名称，也是最后生成的可执行文件名
project(petscSolve3d)

# 语言支持
enable_language(CXX C)

# 支持c++ 11
set(CMAKE_CXX_STANDARD 11)

# 设定编译组态，RelWithDebInfo指优化运行速度同时产生debug信息
# set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")

# 设置源文件和头文件路径
file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/source/*.cpp ${PROJECT_SOURCE_DIR}/test/source/*.cpp)

# 设置头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include/)
include_directories(${PROJECT_SOURCE_DIR}/test/include/)
include_directories(${PROJECT_SOURCE_DIR}/petsc/include/)
include_directories(${PROJECT_SOURCE_DIR}/petsc/include-single/)
include_directories(/opt/intel/oneapi/mpi/latest/include/)

# # 添加预编译
# add_definitions(-DPETSC_USE_REAL_DOUBLE)

# 添加源文件
add_executable(${PROJECT_NAME} ${SRCS})

# 链接库
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/petsc/lib/libpetsc.so)
target_link_libraries(${PROJECT_NAME} /opt/intel/oneapi/mpi/2021.3.0/lib/release/libmpi.so.12)