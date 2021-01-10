cmake_minimum_required(VERSION 3.1)

project(complejos              

    VERSION 1.0
    DESCRIPTION "Un proyecto de Cmake para la tarea 2 de la practica 12"
    LANGUAGES CXX)

add_executable(complejos
    src/complejos.h
    src/complejos.cc)

target_compile_features(fechas PRIVATE cxx_std_14)
target_compile_options(fechas PRIVATE -Wall -Wextra -Wpedantic)
