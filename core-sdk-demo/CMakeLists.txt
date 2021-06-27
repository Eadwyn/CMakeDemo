#############################################################################
# 开始 自定义项目配置
#############################################################################
set(_T_CURRENT_PATH "${PROJECT_SOURCE_DIR}/core-sdk-demo")
# 本工程SDK库项目的根目录
set(_T_PROJECT_SELF_LIBS_ROOT_PATH "${PROJECT_SOURCE_DIR}/core-sdk")
# 本工程SDK库列表：在子项目CMakeLists.txt的add_library取的名称，按依赖项从高到低排序
set(_T_PROJECT_SELF_LIBS CoreSdk_shared)

# 查找当前目录下的所有源文件，
# 并将名称保存到_T_LIB_SOURCES目录
#aux_source_directory(. _T_LIB_SOURCES)

# 头文件目录
set(_T_HEADERS_DIRECTORIES 
    "${_T_CURRENT_PATH}/src"
    "${_T_CURRENT_PATH}/src/test"
    "${PROJECT_SOURCE_DIR}/modules/include")
set(_T_HEADERS_DIRECTORIES 
    ${_T_HEADERS_DIRECTORIES}
    "${_T_PROJECT_SELF_LIBS_ROOT_PATH}/libs/include")
# 源码：下面二选一
#set(_T_SOURCES ${_T_CURRENT_PATH}/src/*.cpp ${_T_CURRENT_PATH}/src/test/*.cpp)
file(GLOB_RECURSE _T_HEADERS "${_T_CURRENT_PATH}/src/*.h")
file(GLOB_RECURSE _T_SOURCES "${_T_CURRENT_PATH}/src/*.cpp")

# 三方库： set(_T_THIRD_LIBS NAMES <name1> <name2> ... PATHS <path1> <path2>)
set(_T_THIRD_LIBS NAMES "" PATHS "")

# 可执行文件名
set(_T_EXECUTE_NAME CoreSdkDemo)
#############################################################################
# 结束 自定义项目配置
#############################################################################




#############################################################################
# 开始 目录配置
#############################################################################
# 头文件目录
foreach(_ITEM ${_T_HEADERS_DIRECTORIES})
    include_directories(${_ITEM})
endforeach(_ITEM)

# 可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${_T_CURRENT_PATH}/bin)
#############################################################################
# 结束 目录配置
#############################################################################




#############################################################################
# 结束 可执行配置
#############################################################################
# 在指定目录下查找库，并保存在LIBPATH变量中
if (_T_THIRD_LIBS)
    find_library(_T_LINK_LIBS ${_T_THIRD_LIBS})
endif()

# 生成目标
#add_executable(${_T_EXECUTE_NAME} main.cpp)
add_executable(${_T_EXECUTE_NAME} ${_T_SOURCES})

message("====================================================")
message("INCLUDE DIRECTORIES:")
message("${_T_HEADERS_DIRECTORIES}")
message("====================================================")

# 链接库
# 此处会链接错误，因为执行该命令时，依赖的动态库/静态库还未生成，因此找不到相关的库
#target_link_libraries(${_T_EXECUTE_NAME} ${_T_EXECUTE_NAME} ${_T_LINK_LIBS})

if (_T_LINK_LIBS)
    message("====================================================")
    message("LINK LIBS:")
    message("${_T_LINK_LIBS}")
    message("====================================================")
    target_link_libraries(${_T_EXECUTE_NAME} ${_T_PROJECT_SELF_LIBS} ${_T_LINK_LIBS})
else()
    message("====================================================")
    message("THIRD LINK LIBS:")
    message("无")
    message("====================================================")
    target_link_libraries(${_T_EXECUTE_NAME} ${_T_PROJECT_SELF_LIBS})
endif()

message("====================================================")
message("SELF LINK LIBS:")
message("${_T_PROJECT_SELF_LIBS}")
message("====================================================")
#############################################################################
# 结束 可执行配置
#############################################################################