//
// Created by parad on 15/05/2020.
//

#ifndef PROJET1C_FONCTION_LIVRE_H
#define PROJET1C_FONCTION_LIVRE_H
#include "fonction_membre.h"
#include "fonction_livre.h"
#include "gestion_bin.h"
typedef struct {
    int jour;
    int mois;
    int annee;
}date;

typedef struct {
    char theme[3];
    int numero;
}code_livre;
typedef struct {
    code_livre code;
    date date_pret;
}liste_pretes;

typedef struct {
    code_livre code;
    char auteur[30];
    char titre[30];
    int exemplaire;
    int nb_pretes;

}livre;

#endif //PROJET1C_FONCTION_LIVRE_H
