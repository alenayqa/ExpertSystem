cmake_minimum_required(VERSION 3.5)
project(shell)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


include_directories(include/)
add_executable(${PROJECT_NAME} 
    test.cpp 
    src/variable.cpp
    src/domain.cpp
    src/rule.cpp
)