cmake_minimum_required(VERSION 3.16)
set(LIB_API Yolo11Cls)
project(${LIB_API} C CXX)
set(CMAKE_CXX_STANDARD 17)
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(${LIB_API} SHARED ${SRC_FILES})
target_include_directories(${LIB_API} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE TEST_SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/test_src/*.cpp")
add_executable("${LIB_API}-test" ${TEST_SRC_FILES})
target_include_directories("${LIB_API}-test" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries("${LIB_API}-test" ${LIB_API})

include("${CMAKE_CURRENT_SOURCE_DIR}/third_party/third_party.cmake")
