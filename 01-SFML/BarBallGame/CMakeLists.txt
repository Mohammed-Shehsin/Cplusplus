cmake_minimum_required(VERSION 3.5)

project(BarBallGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR "C:/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(BarBallGame main.cpp Arial.ttf)

install(TARGETS BarBallGame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
target_link_libraries(BarBallGame sfml-graphics sfml-audio)
target_include_directories(BarBallGame PRIVATE "C:/SFML-2.5.1/include")

install(TARGETS BarBallGame
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
