cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

project(hw01)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses)

add_executable(hw01 main.cpp)
target_link_libraries(hw01 curses)
