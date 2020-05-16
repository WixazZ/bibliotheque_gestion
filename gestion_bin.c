//
// Created by parad on 02/05/2020.
//

#include <stdio.h>
#include "fonction_membre.h"
#include "gestion_bin.h"
/*/////////////////////////////////////////////////GENERAL////////////////////////////////////////////////////////////*/
FILE * ouverture_TXT(char* fichier, char* mode,FILE* fich){
    fich = fopen(fichier, mode);
    return fich;
}
/*/////////////////////////////////////////////FIN GENERAL////////////////////////////////////////////////////////////*/

//difficulte comprendre le fonctionnement due binaire dans des fichier et d'aller chercher les donnéesque l'on recherche

/*///////////////////////INITIALISATION FICHIER ET RECUPERATION DANS DES STRUCTURES///////////////////////////////////*/
int nombre_membre_ou_livre(char * fichier,int data)
{
    int n=0;
    FILE *fich = NULL;
    if (data==1){
        fich = ouverture_TXT(fichier, "rb",fich);
        membre e;
        while(fread(&e,sizeof(membre), 1, fich))
            n++;
        fclose(fich);
    } else{
        fich = ouverture_TXT(fichier, "rb",fich);
        livre e;
        while(fread(&e,sizeof(livre), 1, fich))
            n++;
        fclose(fich);
    }
    return n;
}

membre * recup_membres_data() {
    char * membres_liste = "liste_membre.txt";
    int n_membre = nombre_membre_ou_livre(membres_liste, 1);
    FILE *membres_fichier =NULL;
    membres_fichier= ouverture_TXT(membres_liste, "rb", membres_fichier);
    membre recup;
    printf(" nombre de membre : %d",n_membre);
    membre *tab_membre =(membre*)malloc(n_membre*sizeof(membre));
    //int unsigned c;
    for (int j = 0; j < n_membre; ++j) {
        /*c =*/ fread(&recup, sizeof(membre), 1, membres_fichier);
        //printf("coucou %d",c);
        tab_membre[j]=recup;
    }
    //printf("\n\n\nnom : %s",tab_membre[0].nom);
    //printf("\n\n\nprenom : %s\n\n\n",tab_membre[0].prenom);
    fclose(membres_fichier);
    return tab_membre;
}
livre * recup_livres_data() {

    char * livre_liste = "liste_livre.txt";
    int n_livre = nombre_membre_ou_livre(livre_liste, 0);
    printf(" nombre de livre : %d",n_livre);
    livre *tab_livre =(livre*)malloc(n_livre * sizeof(livre));
    FILE *livre_fichier =NULL;
    livre_fichier= ouverture_TXT(livre_liste, "rb", livre_fichier);
    livre recup;

    for (int j = 0; j < n_livre; ++j) {
        fread(&recup, sizeof(livre), 1, livre_fichier);
        tab_livre[j] = recup;
    }
    fclose(livre_fichier);
    return tab_livre;
}
/*//////////////////////////////////////////////FIN D INITIALISATION//////////////////////////////////////////////////*/

/*////////////////////////////////////////////SORTIE ET ENVOIE DES TABLEAUX DANS LE TEXTE/////////////////////////////*/
void renvoie_membres_data(membre *tab_membre){
    char * fichier = "liste_membre.txt";
    FILE *membres_fichier = fopen(fichier, "wb+");
    fwrite (tab_membre, sizeof(membre), sizeof(*tab_membre), membres_fichier);
    fclose(membres_fichier);
}
void renvoie_livres_data(livre *tab_livres){
    char * fichier = "liste_livre.txt";
    FILE *livres_fichier = fopen(fichier, "wb+");
    fwrite (tab_livres, sizeof(livre), sizeof(*tab_livres), livres_fichier);
    fclose(livres_fichier);
}
/*////////////////////////////////////////////FIN DE SORTIE ET DES FONCTIONS//////////////////////////////////////////*/
