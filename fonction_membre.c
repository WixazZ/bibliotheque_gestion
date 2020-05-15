//
// Created by parad on 15/05/2020.
//

#include "fonction_membre.h"
#include "fonction_livre.h"

/*
#include <string.h>
void demande_adresse(adresse * membre_adresse){
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
void remplir_fichier_membre(){
    FILE * fichier=fopen("liste_membre","w+");
    //char nom[30], prenom[30],mail[30], metier[30];
    membre* new, new1;
    printf("Rentrer Nom : ");
    fflush(stdin);
    scanf("%s", new->nom);
    printf("Rentrer prenom : ");
    fflush(stdin);
    scanf("%s", new->prenom);
    *demande_adresse(m->adresse_membre);*
    printf("Rentrer mail : ");
    fflush(stdin);
    scanf("%s", new->mail);
    printf("Rentrer metier : ");
    fflush(stdin);
    scanf("%s", new->metier);
    fwrite(new, sizeof(membre),1,fichier);
    fclose(fichier);
    fichier=fopen("liste_membre","w+");
    int x = fread(&new1,sizeof(membre),1,fichier);
    printf("x: %d",x);
    printf("nom : %s",new1.nom);
    fclose(fichier);
}

void f_adresse(adresse* a, FILE* fichier){
    fprintf(fichier,"%d, %s %d %s ", a->numero, a->voie, a->CP, a->ville);
}
int ajout_membre(){
    membre * new;

    remplir_fichier_membre();
/*
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