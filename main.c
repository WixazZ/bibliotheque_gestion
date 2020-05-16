//
// Created by parad on 01/05/2020.
//
#include<stdio.h>
#include "fonction_membre.h"
#include "gestion_bin.h"

int main(){
    membre *tab_membre = recup_membres_data();
    livre *tab_livre = recup_livres_data();
    remplir_fichier_membre(&tab_membre[0]);
    renvoie_livres_data(tab_livre);
    renvoie_membres_data(tab_membre);
    return 0;
}
