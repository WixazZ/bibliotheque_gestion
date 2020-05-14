//
// Created by parad on 02/05/2020.
//

#ifndef PROJET2C_FONCTIONS_H
#define PROJET2C_FONCTIONS_H
#include <stdlib.h>
#include <stdio.h>



typedef struct {
    int jour;
    int mois;
    int annee;
}date;
typedef struct{
    int numero;
    char voie[100];
    int CP;
    char ville[50];
}adresse;
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

typedef struct {
    char nom[50];
    char prenom[50];
    adresse adresse_membre;
    char mail[50];
    char metier[50];
    liste_pretes liste_pret_membre[3];
}membre;

membre* recup_membres_data();
livre* recup_livres_data();
int ajout_membre();
#endif //PROJET2C_FONCTIONS_H
