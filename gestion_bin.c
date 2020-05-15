//
// Created by parad on 02/05/2020.
//

#include <stdio.h>
#include "fonction_membre.h"
#include "gestion_bin.h"


/*///////////////////////INITIALISATION FICHIER ET RECUPERATION DANS DES STRUCTURES///////////////////////////////////*/
membre* recup_membres_data() {
    FILE *membres_fichier = fopen("liste_membre.txt", "rb");
    int n_membres = ftell(membres_fichier)/sizeof(membre);
    membre * tab_membre = (membre*)malloc(n_membres * sizeof(membre));

    for (int i = 0; i < feof(membres_fichier) == 0; ++i) {
        printf("test1");
        fread(&tab_membre[i], sizeof(membre), 1, membres_fichier);
        printf("test");
    }
    fclose(membres_fichier);
    return tab_membre;
}
livre* recup_livres_data() {

    FILE *livres_fichier = fopen("liste_livre.txt", "rb");
    int n_livre = ftell(livres_fichier)/sizeof(livre);
    livre * tab_livres = (livre *)malloc(n_livre * sizeof(membre));
    for (int i = 0; i < feof(livres_fichier) == 0; ++i) {
        fread(&tab_livres[i], sizeof(livre), 1, livres_fichier);
    }
    fclose(livres_fichier);
    printf("test");
    return tab_livres;

}
/*//////////////////////////////////////////////FIN D INITIALISATION//////////////////////////////////////////////////*/


/*////////////////////////////////////////////SORTIE ET ENVOIE DES TABLEAUX DANS LE TEXTE/////////////////////////////*/
void renvoie_membres_data(membre *tab_membre){
    FILE *membres_fichier = fopen("liste_membre.txt", "wb+");
    fwrite (tab_membre, sizeof(tab_membre), sizeof(*tab_membre), membres_fichier);
}
void renvoie_livres_data(livre *tab_livres){
    FILE *livres_fichier = fopen("liste_livre.txt", "wb+");
    fwrite (tab_livres, sizeof(tab_livres), sizeof(*tab_livres), livres_fichier);
}
/*////////////////////////////////////////////FIN DE SORTIE ET DES FONCTIONS//////////////////////////////////////////*/
