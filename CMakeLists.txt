cmake_minimum_required(VERSION 3.5)

project(KozelTheGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(KozelTheGame main.cpp
    card.hpp card.cpp
    deck.hpp deck.cpp
    game.hpp game.cpp
    player.hpp player.cpp
    iuserinterface.hpp
    textui.hpp textui.cpp
    worku32srting.hpp worku32srting.cpp)
