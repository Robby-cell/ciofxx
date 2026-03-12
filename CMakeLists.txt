cmake_minimum_required(VERSION 3.16)

project(ciofxx LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ciof)
target_include_directories(ciof
    PRIVATE
        ${PROJECT_SOURCE_DIR}/Include
)
add_subdirectory(Source)
