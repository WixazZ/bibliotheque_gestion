//
// Created by parad on 15/05/2020.
//


#include "fonction_livre.h"
#include "gestion_bin.h"
#include <stdio.h>

/*/////////////////////////////////AJOUTER LIVRE//////////////////////////////////////////////////////////////////////*/

void addLivre(livre* new_livre){

    printf("\nCode du livre :\n");
    printf("Theme de livre\n");
    scanf("%s",new_livre->code.theme);
    printf("numero du livre\n");
    scanf("%d",&new_livre->code.numero);
    printf("Auteur\n");
    scanf("%s",new_livre->auteur);
    printf("Titre\n");
    scanf("%s",new_livre->titre);
    printf("Nombre d'exemplaires\n");
    scanf("%d",&new_livre->exemplaire);
    printf("Nombre d'exemplaires disponnibles\n");
    scanf("%d",&new_livre->dispo);

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

/*/////////////////////////////////AFFICHER LES TRI//////////////////////////////////////////////////////////////////////*/

void disptricode (){

}
void disptrinombre (){
    int buffer;
    for (int i = 0 ; i < total.n_livre; i++) {
        if (total.liste_livre[i].exemplaire > total.liste_livre[i + 1].exemplaire) {
            buffer = total.liste_livre[i].exemplaire;
            total.liste_livre[i].exemplaire = total.liste_livre[i + 1].exemplaire;
            total.liste_livre[i + 1].exemplaire = buffer;
        }
    }
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
    switch (choixtri) {
        case 1 : disptricode();
            break;
        /*case 2 : disptrititre();
            break;
        case 3 : disptriauteur();
            break;*/
        case 4 : disptrinombre();
            break;
    }
}
