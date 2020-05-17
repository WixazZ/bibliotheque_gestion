//
// Created by parad on 01/05/2020.
//
#include<stdio.h>
#include "fonction_membre.h"
#include "gestion_bin.h"

int main(){
    biblio total;
    recup_data(&total);
    ajout_membre(&total);
    renvoie_data(&total);
    /*remplir_fichier_membre(&total.liste_membre[0]);
    printf("%s", total.liste_membre[0].nom);
    printf("%s", total.liste_membre[0].prenom);
    printf("%d", total.liste_membre[0].adresse_membre.CP);
    printf("%s", total.liste_membre[0].adresse_membre.voie);*/

    //membre *tab_membre = recup_membres_data();
    //printf("%s", tab_membre[0].nom);
    //livre *tab_livre = recup_livres_data();
    //membre *tab_membre = (membre*)malloc(sizeof(membre));
    //membre test_membre;
    //tab_membre [0] = test_membre;

    //remplir_fichier_membre(&tab_membre[0]);
    //renvoie_membres_data(tab_membre);
    //renvoie_livres_data(tab_livre);

    return 0;
}
