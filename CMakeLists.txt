# CMake最低版本号要求
cmake_minimum_required(VERSION 3.10.1)

# 项目名称&版本
# 会同时创建PROJECT_BINARY_DIR、PROJECT_SOURCE_DIR、CMakeDemo_BINARY_DIR、CMakeDemo_SOURCE_DIR
# PROJECT_VERSION、CMakeDemo_VERSION变量
project(CMakeDemo VERSION "0.0.1")


#############################################################################
# 开始 自定义项目配置
#############################################################################
# 编译类型：empty or [Debug, Release, RelWithDebInfo, MinSizeRel]
set(_T_BUILD_TYPE Debug)

# 添加CMake子目录
# set(_T_SUB_DIRECTIES ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src_lib)
set(_T_SUB_DIRECTIES "${PROJECT_SOURCE_DIR}/core-sdk" "${PROJECT_SOURCE_DIR}/core-sdk-demo")
#############################################################################
# 结束 自定义项目配置
#############################################################################



# 若是需要指定编译器路径
#set(CROSS_TOOLCHAIN_PREFIX "/path/arm-linux-")
# 指定编译器
#set(CMAKE_C_COMPILER "${CROSS_TOOLCHAIN_PREFIX}gcc")
#set(CMAKE_CXX_COMPILER "${CROSS_TOOLCHAIN_PREFIX}g++")

# 使用默认路径的g++指定编译器 
set(CMAKE_CXX_COMPILER "g++") 

# 指定编译选项
set(CMAKE_T_BUILD_TYPE ${_T_BUILD_TYPE})

# 指定编译目录
set(PROJECT_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# 添加子目录
foreach(_ITEM ${_T_SUB_DIRECTIES})
    add_subdirectory(${_ITEM})
endforeach(_ITEM)
