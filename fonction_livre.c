//
// Created by parad on 15/05/2020.
//


#include "fonction_livre.h"
#include <stdlib.h>
#include <stdio.h>

void dispLivre (livre* livre1){
    printf("code : ");
    dispCode(livre1->code);
    printf("Auteur : %s\n",livre1->auteur);
    printf("Titre : %s\n",livre1->titre);
    printf("Nombre d'exemplaires : %d\n",livre1->exemplaire);
    printf("Nombre d'exemplaires disponnibles : %d\n",livre1->dispo);
}
void addLivre(livre* livre1){

    printf("Code du livre\n");
    //addCode(&livre1->code);
    printf("Theme de livre\n");
    scanf("%s",livre1->code.theme);
    printf("numero du livre\n");
    scanf("%d",&livre1->code.numero);
    printf("test 1\n");
    printf("Auteur\n");
    scanf("%s",livre1->auteur);
    printf("Titre\n");
    scanf("%s",livre1->titre);
    printf("Nombre d'exemplaires\n");
    scanf("%d",&livre1->exemplaire);
    printf("Nombre d'exemplaires disponnibles\n");
    scanf("%d",&livre1->dispo);
}
void dispCode(code_livre code1) {
    printf("%s", code1.theme);
    printf("-");
    printf("%d", code1.numero);
    printf("\n");
}