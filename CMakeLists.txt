cmake_minimum_required(VERSION 3.25)
project(CalcuSortTime)

set(CMAKE_CXX_STANDARD 23)
message("projected by HuangJingyang 2023 \n")

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(
        ${PROJECT_SOURCE_DIR}/include/
)

add_library(${PROJECT_NAME}
        src/runTime.cpp
        src/sort.cpp
        )

add_executable(testSort example/sortTime.cpp)
add_executable(testSum example/sumTime.cpp)

target_link_libraries(testSort
        ${PROJECT_NAME}
        )