//
// Created by parad on 02/05/2020.
//

#include <stdio.h>
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
membre * recup_membres_data(biblio* total) {
    char * membres_liste = "liste_membre.txt";
    total->n_membre = nombre_membre_ou_livre(membres_liste, 1);
    FILE *membres_fichier =NULL;
    membres_fichier= ouverture_TXT(membres_liste, "rb", membres_fichier);
    membre recup;
    printf(" nombre de membre : %d\n",total->n_membre);
    membre *tab_membre =(membre*)malloc(total->n_membre*sizeof(membre));
    //int unsigned c;
   for (int j = 0; j < total->n_membre; ++j) {
        /*c =*/ fread(&recup, sizeof(membre), 1, membres_fichier);
        //printf("coucou %d",c);
        tab_membre[j]=recup;
    }
    //printf("\n\n\n%d\n\n\n",sizeof(*tab_membre));
    //printf("\n\n\nnom : %s",tab_membre[0].nom);
    //printf("\n\n\nprenom : %s\n\n\n",tab_membre[0].prenom);
    fclose(membres_fichier);
    return tab_membre;
}
livre * recup_livres_data(biblio* total) {

    char * livre_liste = "liste_livre.txt";
    total->n_livre = nombre_membre_ou_livre(livre_liste, 0);
    printf(" nombre de livre : %d",total->n_livre);
    livre *tab_livre =(livre*)malloc(total->n_livre * sizeof(livre));
    FILE *livre_fichier =NULL;
    livre_fichier= ouverture_TXT(livre_liste, "rb", livre_fichier);
    livre recup;

    for (int j = 0; j < total->n_livre; ++j) {
        fread(&recup, sizeof(livre), total->n_livre, livre_fichier);
        tab_livre[j] = recup;
    }
    fclose(livre_fichier);
    return tab_livre;
}
/*//////////////////////////////////////////////FIN D INITIALISATION//////////////////////////////////////////////////*/

/*////////////////////////////////////////////SORTIE ET ENVOIE DES TABLEAUX DANS LE TEXTE/////////////////////////////*/
void renvoie_membres_data(membre *tab_membre, int n_membre){
    char * fichier = "liste_membre.txt";
    FILE *membres_fichier =NULL;
    membre recup;
    n_membre = 1;
    membres_fichier = ouverture_TXT( fichier,"wb+" ,membres_fichier);
    for (int i = 0; i < n_membre; ++i) {
        recup = tab_membre[i];
        fwrite (&recup, sizeof(membre), n_membre, membres_fichier);
    }
    fclose(membres_fichier);
}

void renvoie_livres_data(livre *tab_livre, int n_livre){
    char * fichier = "liste_livre.txt";
    FILE *livres_fichier =NULL;
    livre recup;
    livres_fichier = ouverture_TXT( fichier,"wb+" ,livres_fichier);
    for (int i = 0; i < n_livre; ++i) {
        recup = tab_livre[i] ;
        fwrite(&recup, sizeof(livre), n_livre, livres_fichier);
    }
    fclose(livres_fichier);
}
/*////////////////////////////////////////////FIN DE SORTIE ET DES FONCTIONS//////////////////////////////////////////*/
void recup_data(biblio* total){
    total->liste_membre= recup_membres_data(total);
    total->liste_livre = recup_livres_data(total);
}
void renvoie_data(biblio* total){
    renvoie_membres_data(total->liste_membre, total->n_membre);
    renvoie_livres_data(total->liste_livre, total->n_livre);
}

membre* increaseMembreSizeByOne(biblio* total) {
    total->n_membre++;
    membre* temp = (membre* ) malloc(total->n_membre*sizeof(membre));
    for (int i=0; i<total->n_membre-1; i++) {
        temp[i] = total->liste_membre[i];
    } free(total->liste_membre);
    return(temp);
}
/*
livre* increaseLivreSizeByOne(livre* liste_livre) {
    n_livre++;
    livre* temp = (livre* ) malloc(n_livre*sizeof(livre));
    for (int i=0; i<n_livre-1; i++) {
        temp[i] = liste_livre[i];
    } free(liste_livre);
    return(temp);
}*/