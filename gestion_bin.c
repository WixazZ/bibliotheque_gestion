//
// Created by parad on 02/05/2020.
//

#include <stdio.h>
#include "fonction_membre.h"
#include "gestion_bin.h"

//difficulte comprendre le fonctionnement due binaire dans des fichier et d'aller chercher les donnéesque l'on recherche
/*///////////////////////INITIALISATION FICHIER ET RECUPERATION DANS DES STRUCTURES///////////////////////////////////*/
int nombre_membre_ou_livre(char * fichier,int data)
{
    int n=0;
    FILE * fich;
    fich=fopen(fichier, "r+");
    if (data==1){
        membre e;
        while(fread(&e,sizeof(membre), 1, fich))
            n++;
    } else{
        livre e;
        while(fread(&e,sizeof(membre), 1, fich))
            n++;
    }

    fclose(fich);
    return n;
}

membre * recup_membres_data() {
    char * membres_liste = "liste_membre.txt";
    FILE *membres_fichier = fopen( membres_liste, "rb");
    membre recup;
    int n_membre = nombre_membre_ou_livre(membres_liste, 1);
    printf("%d",n_membre);
    membre *tab_membre =(membre*)malloc(n_membre*sizeof(membre));
    for (int j = 0; j < n_membre; ++j) {
        fread(&recup, sizeof(membre), 1, membres_fichier);
        tab_membre[j]=recup;
    }
    fclose(membres_fichier);
    return tab_membre;
}
livre * recup_livres_data() {
    char * livre_liste = "liste_livre.txt";
    FILE *livre_fichier = fopen( livre_liste, "rb");
    livre recup;
    int n_livre = nombre_membre_ou_livre(livre_liste, 0);
    livre *tab_livre =(livre *)malloc(n_livre*sizeof(livre));
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
    FILE *membres_fichier = fopen("liste_membre.txt", "wb+");
    fwrite (tab_membre, sizeof(tab_membre), sizeof(*tab_membre), membres_fichier);
}
void renvoie_livres_data(livre *tab_livres){
    FILE *livres_fichier = fopen("liste_livre.txt", "wb+");
    fwrite (tab_livres, sizeof(tab_livres), sizeof(*tab_livres), livres_fichier);
}
/*////////////////////////////////////////////FIN DE SORTIE ET DES FONCTIONS//////////////////////////////////////////*/
