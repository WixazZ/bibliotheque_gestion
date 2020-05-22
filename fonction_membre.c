//
// Created by parad on 15/05/2020.
//
#include "gestion_bin.h"
#include "fonction_membre.h"
#include <stdio.h>
#include <string.h>


/*////////////////////////////////AJOUTER MEMBRE//////////////////////////////////////////////////////////////////////*/
void demande_adresse(adresse* membre_adresse){
    printf("Adresse :\n");
    printf("Rentrer numero : ");
    fflush(stdin);
    scanf("%d",&membre_adresse->numero);
    printf("Rentrer voie : ");
    fflush(stdin);
    gets(membre_adresse->voie);
    printf("Rentrer Code Postal : ");
    fflush(stdin);
    scanf("%d",&membre_adresse->CP);
    printf("Rentrer ville : ");
    fflush(stdin);
    scanf("%s",membre_adresse->ville);
}
void remplir_fichier_membre(membre* tab_membre){
    //char nom[30], prenom[30],mail[30], metier[30];
    printf("Rentrer NOM : ");
    fflush(stdin);
    scanf("%s", tab_membre->nom);
    printf("Rentrer Prenom : ");
    fflush(stdin);
    scanf("%s", tab_membre->prenom);
    demande_adresse(&tab_membre->adresse_membre);
    printf("Rentrer mail : ");
    fflush(stdin);
    scanf("%s", tab_membre->mail);
    printf("Rentrer metier : ");
    fflush(stdin);
    scanf("%s", tab_membre->metier);
}

void ajout_membre(){
    total.liste_membre = increaseMembreSizeByOne(&total);
    remplir_fichier_membre(&total.liste_membre[total.n_membre-1]);
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////AFFICHER MEMBRE/////////////////////////////////////////////////////////////////////*/

void afficher_all_membre(){
    for (int i = 0; i < total.n_membre; ++i) {
        afficher_membre(i);
    }
}
void afficher_membre(int id_membre){
    printf("\n*********************\n");
    printf("     member n %d\n",id_membre);
    printf("*********************\n");
    printf("NOM : %s\n",total.liste_membre[id_membre].nom);
    printf("Prenom : %s\n",total.liste_membre[id_membre].prenom);
    printf("Adresse : %d %s, %d, %s\n",total.liste_membre[id_membre].adresse_membre.numero,total.liste_membre[id_membre].adresse_membre.voie,total.liste_membre[id_membre].adresse_membre.CP,total.liste_membre[id_membre].adresse_membre.ville);
    printf("Email : %s\n",total.liste_membre[id_membre].mail);
    printf("Métier : %s\n",total.liste_membre[id_membre].metier);
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/



/*///////////////////////////////SUPPRIMER MEMBRE/////////////////////////////////////////////////////////////////////*/
void DeplacerMembreFinDeListe(int id){
    membre a_suppr = total.liste_membre[id];
    for (int i = id; i < total.n_membre-1; ++i) {
        total.liste_membre[i] = total.liste_membre[i+1];
    }
    total.liste_membre[total.n_membre-1] = a_suppr;

}
void delete_membre(){
    int id_delete_membre ;
    printf("Rentre le membre que vous voulez supprimer : ");
    scanf("%d",&id_delete_membre);
    DeplacerMembreFinDeListe(id_delete_membre);
    total.n_membre--;
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


/*
void f_adresse(adresse* a, FILE* fichier){
    fprintf(fichier,"%d, %s %d %s ", a->numero, a->voie, a->CP, a->ville);
}
int ajout_membre(){
    membre * new;

    remplir_fichier_membre();

    if (fichier!=NULL){
        fwrite(new,sizeof(membre*),1,fichier);
    } else{
        return 1;
    }
    return 0;
}*/
/*
membre new;
remplir_membre(&new);
FILE* fichier = NULL;
fichier=fopen("liste_membre.txt","a+");

if (fichier!=NULL){
    fprintf(fichier,"%s %s ",new.nom,new.prenom);
    f_adresse(&new.adresse_membre, fichier);
    fprintf(fichier,"%s %s\n",new.mail,new.metier);
    fclose(fichier);
} else{
    return 1;
}
return 0;
}
 */
/*
int cherche_membre(){
    char str[60];

    opening file for reading
    fichier = fopen("file.txt" , "r");
    if(fichier == NULL) {
        perror("Error opening file");
        return(-1);
    }
    if( fgets (str, 60, fichier)!=NULL ) {
         writing content to stdout
        puts(str);
    }
    fclose(fichier);

    return(0);
}
*/