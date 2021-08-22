cmake_minimum_required(VERSION 3.5)

project(KozelTheGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KozelTheGame main.cpp
    card.h card.cpp
    deck.h deck.cpp
    game.h game.cpp
    player.h player.cpp
    irendersystem.h
    textrender.h textrender.cpp
    worku32srting.h worku32srting.cpp)
