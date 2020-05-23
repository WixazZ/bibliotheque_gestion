//
// Created by parad on 15/05/2020.
//


#include "fonction_livre.h"
#include "gestion_bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*/////////////////////////////////AJOUTER LIVRE//////////////////////////////////////////////////////////////////////*/

void addLivre(livre* new_livre){

    printf("\nCode du livre :\n");
    printf("Theme de livre\n");
    scanf("%s",new_livre->code.theme);
    printf("numero du livre\n");
    scanf("%d",&new_livre->code.numero);
    fflush(stdin);
    printf("Auteur\n");
    fgets(new_livre->auteur,sizeof(new_livre->auteur),stdin);
    printf("Titre\n");
    fgets(new_livre->titre,sizeof(new_livre->titre),stdin);

    printf("\nNombre d'exemplaires\n");
    scanf("%d",&new_livre->exemplaire);
    new_livre->dispo = new_livre->exemplaire;

}

void ajout_livre(){
    total.liste_livre = increaseLivreSizeByOne(&total);
    addLivre(&total.liste_livre[total.n_livre-1]);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*/////////////////////////////////AJOUTER LIVRE//////////////////////////////////////////////////////////////////////*/

void afficher_all_livre(){
    for (int i = 0; i < total.n_livre; ++i) {
        afficher_livre(i);
    }
}

void dispCode(code_livre code) {
    printf("%s", code.theme);
    printf("-");
    printf("%d", code.numero);
}

void afficher_livre(int id_livre){
    printf("\n*********************\n");
    printf("     livre n %d\n",id_livre);
    printf("*********************\n");
    printf("Code : ");
    dispCode(total.liste_livre[id_livre].code);
    printf("\nAuteur : %s", total.liste_livre[id_livre].auteur);
    printf("\nTitre : %s", total.liste_livre[id_livre].titre);
    printf("\nNombre d'exemplaire : %d", total.liste_livre[id_livre].exemplaire);
    printf("\nNombre de dispo : %d\n", total.liste_livre[id_livre].dispo);
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*/////////////////////////////////AFFICHER LES TRI///////////////////////////////////////////////////////////////////*/

void disptriCode (){
    livre buffer;
    int bufferint;
    for (int i = 0; i < total.n_livre; ++i) {
        for (int j = 0; j < total.n_livre; ++j){
            if (strcmp(total.liste_livre[i].code.theme, total.liste_livre[j].code.theme)<0){
                buffer = total.liste_livre[i];
                total.liste_livre[i] = total.liste_livre[j];
                total.liste_livre[j] = buffer;
            }
        }
    }
    for (int i = 0 ; i < total.n_livre; i++) {
        if (total.liste_livre[i].code.numero > total.liste_livre[i + 1].code.numero ) {
            bufferint = total.liste_livre[i].code.numero ;
            total.liste_livre[i].code.numero  = total.liste_livre[i + 1].code.numero ;
            total.liste_livre[i + 1].code.numero  = bufferint;
        }
    }
}
void disptriNombre (){
    int buffer;
    for (int i = 0 ; i < total.n_livre; i++) {
        if (total.liste_livre[i].exemplaire > total.liste_livre[i + 1].exemplaire) {
            buffer = total.liste_livre[i].exemplaire;
            total.liste_livre[i].exemplaire = total.liste_livre[i + 1].exemplaire;
            total.liste_livre[i + 1].exemplaire = buffer;
        }
    }
    afficher_all_livre();
}
void disptriTitre(){
    livre buffer;
    for (int i = 0; i < total.n_livre; ++i) {
        for (int j = 0; j < total.n_livre; ++j){
            if (strcmp(total.liste_livre[i].titre, total.liste_livre[j].titre)<0){
                buffer = total.liste_livre[i];
                total.liste_livre[i] = total.liste_livre[j];
                total.liste_livre[j] = buffer;
            }
        }
    }
    afficher_all_livre();
}
void disptriAuteur(){
    livre buffer;
    for (int i = 0; i < total.n_livre; ++i) {
        for (int j = 0; j < total.n_livre; ++j){
            if (strcmp(total.liste_livre[i].auteur, total.liste_livre[j].auteur)<0){
                buffer = total.liste_livre[i];
                total.liste_livre[i] = total.liste_livre[j];
                total.liste_livre[j] = buffer;
            }
        }
    }
    afficher_all_livre();
}


void dispListeLivres(){
    int choixtri = 5;
    printf("choisissez le type d'affichage\n");
    printf("    -1 pour le tri par code\n");
    printf("    -2 pour le tri par titre\n");
    printf("    -3 pour le tri par auteur\n");
    printf("    -4 pour le tri par nombre d'exemplaire\n");
    printf("    -0 pour quitter le menu");
    while (choixtri != 0 && choixtri != 1 && choixtri != 2 && choixtri != 3 && choixtri != 4 ) {
        scanf("%d", &choixtri);
    }
    switch(choixtri) {
        case 1 : disptriCode();
            break;
        case 2 : disptriTitre();
            break;
        case 3 : disptriAuteur();
            break;
        case 4 : disptriNombre();
            break;
    }
}
