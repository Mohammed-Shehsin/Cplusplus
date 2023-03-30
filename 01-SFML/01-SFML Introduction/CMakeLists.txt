cmake_minimum_required(VERSION 3.5)

project(SFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SFML main.cpp)

install(TARGETS SFML
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_include_directories(${PROJECT_NAME} PRIVATE "C:/SFML-2.5.1/include")
