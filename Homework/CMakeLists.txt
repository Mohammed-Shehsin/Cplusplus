cmake_minimum_required(VERSION 3.5)

project(Homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Homework main.cpp )
file(COPY grass.png wall.png guy.png youwin.jpg DESTINATION ${CMAKE_BINARY_DIR})


install(TARGETS Homework
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-audio)
target_include_directories(${PROJECT_NAME} PRIVATE "C:/SFML-2.5.1/include")
