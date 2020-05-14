# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(projet1c)

# Crée des variables avec les fichiers à compiler
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(SRCS
        main.c
        fonctions.c
        )

set(HEADERS
        fonctions.h
        )


add_executable(projet1c ${SRCS} ${HEADERS})