//
// Created by parad on 01/05/2020.
//
#include<stdio.h>
#include "fonction_membre.h"

int main(){

    recup_data();

    ajout_membre();

    for (int i = 0; i < total.n_membre; ++i) {
        afficher_membre(i);
    }

    renvoie_data();

    return 0;
}
