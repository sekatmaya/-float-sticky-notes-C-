cmake_minimum_required(VERSION 3.16)
project(sticky-notes)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(sticky-notes
    main.cpp
    NotesWindow.cpp
    NotesWindow.h
)

target_link_libraries(sticky-notes PRIVATE Qt6::Widgets)