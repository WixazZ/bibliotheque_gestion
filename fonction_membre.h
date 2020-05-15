//
// Created by parad on 15/05/2020.
//

#ifndef PROJET1C_FONCTION_MEMBRE_H
#define PROJET1C_FONCTION_MEMBRE_H
#include "fonction_livre.h"

typedef struct{
    int numero;
    char voie[100];
    int CP;
    char ville[50];
}adresse;
typedef struct {
    char nom[50];
    char prenom[50];
    adresse adresse_membre;
    char mail[50];
    char metier[50];
    liste_pretes liste_pret_membre[3];
}membre;
void remplir_fichier_membre(membre);
//int ajout_membre();
#endif //PROJET1C_FONCTION_MEMBRE_H
