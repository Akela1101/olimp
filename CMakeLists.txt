cmake_minimum_required(VERSION 3.2)
project(olimp)

set(target A)
set(CMAKE_CXX_STANDARD 17)

add_executable(${target} src/main${target}.cpp)
target_link_libraries(${target} -static)