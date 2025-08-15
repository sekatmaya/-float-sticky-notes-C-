cmake_minimum_required(VERSION 3.5)
project(FloatNoteQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(FloatNoteQt
    main.cpp
    NotesWindow.h
    NotesWindow.cpp
)

target_link_libraries(FloatNoteQt PRIVATE Qt5::Widgets)
