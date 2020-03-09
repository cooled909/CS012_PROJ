cmake_minimum_required(VERSION 3.15)
project(CS012_PROJ)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CS012_PROJ
        BBoard.cpp
        BBoard.h
        main.cpp
        Message.cpp
        Message.h
        User.cpp
        User.h Topic.h Topic.cpp Reply.h Reply.cpp)
