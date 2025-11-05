cmake_minimum_required(VERSION 3.16)
set(MAIN_PROJECT OpenGLExample)
project(${MAIN_PROJECT} C CXX)
set(CMAKE_CXX_STANDARD 17)
if (POLICY CMP0141)
    cmake_policy(SET CMP0141 NEW)
    set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${MAIN_PROJECT} ${SRC_FILES})
target_include_directories(${MAIN_PROJECT} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

include("${CMAKE_CURRENT_SOURCE_DIR}/third_party/third_party.cmake")
