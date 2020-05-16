//
// Created by parad on 15/05/2020.
//

#include "fonction_membre.h"
#include "fonction_livre.h"
#include <stdlib.h>
#include <stdio.h>

int dispListLivre (){

}
int addLivre(){
    livre livre1;
    printf("Code du livre\n");
    addCode(&livre1.code);
    printf("Auteur\n");
    gets(livre1.auteur);
    printf("Titre\n");
    gets(livre1.titre);
    printf("Nombre d'exemplaires\n");
    scanf("%d",&livre1.exemplaire);
    printf("Nombre d'exemplaires prêtés\n");
    scanf("%d",&livre1.nb_pretes);
    return 0;
}
code_livre addCode(code_livre code1){
    printf("Theme de livre");
    scanf("%c",&code1.theme);
    printf("numero du livre");
    scanf("%d",&code1.numero);
    return(code1);
    //test
}