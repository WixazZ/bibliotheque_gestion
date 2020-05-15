//
// Created by parad on 01/05/2020.
//
#include<stdio.h>
#include "fonction_membre.h"
#include "fonction_livre.h"
#include "gestion_bin.h"

int main(){
    membre *tab_membres = recup_membres_data();
    livre *tab_livres = recup_livres_data();
    remplir_fichier_membre(tab_membres);
    renvoie_livres_data(tab_livres);
    renvoie_membres_data(tab_membres);
    return 0;
}