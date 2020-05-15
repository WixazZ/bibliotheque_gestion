cmake_minimum_required(VERSION 3.0)

project(projet1c)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(SRCS
        main.c
        gestion_bin.c
        fonction_membre.c
        fonction_livre.c)

set(HEADERS
        gestion_bin.h
        fonction_membre.h
        fonction_livre.h)


add_executable(projet1c ${SRCS} ${HEADERS})