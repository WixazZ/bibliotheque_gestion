//
// Created by parad on 15/05/2020.
//
#include "gestion_bin.h"
#include "fonction_membre.h"
#include "fonction_livre.h"
#include <stdio.h>
#include <string.h>


/*////////////////////////////////AJOUTER MEMBRE//////////////////////////////////////////////////////////////////////*/

void demande_adresse(adresse* membre_adresse){
    printf("Adresse :\n");
    printf("Rentrer numero : ");
    fflush(stdin);
    scanf("%d",&membre_adresse->numero);
    printf("Rentrer voie : ");
    fgets(membre_adresse->voie, sizeof(membre_adresse->voie), stdin);
    printf("Rentrer Code Postal : ");
    fflush(stdin);
    scanf("%d",&membre_adresse->CP);
    printf("Rentrer ville : ");
    fflush(stdin);
    scanf("%[^\n]",membre_adresse->ville);
}
void remplir_fichier_membre(membre* tab_membre){
    printf("Rentrer NOM : ");
    fgets(tab_membre->nom, sizeof(tab_membre->nom),stdin);
    printf("Rentrer Prenom : ");
    fflush(stdin);
    fgets(tab_membre->prenom, sizeof(tab_membre->prenom),stdin);
    demande_adresse(&tab_membre->adresse_membre);
    printf("Rentrer mail : ");
    fgets(tab_membre->mail, sizeof(tab_membre->mail),stdin);
    printf("Rentrer metier : ");
    fgets(tab_membre->metier, sizeof(tab_membre->metier),stdin);
    tab_membre->n_livre_emprunt = 0;
}


void ajout_membre(){
    total.liste_membre = increaseMembreSizeByOne(&total);
    remplir_fichier_membre(&total.liste_membre[total.n_membre-1]);
}
int verif_membre(membre m){ //verification membre
    int i;

    for (i = 0; i < total.n_membre; i++){
        if ((strcmp(total.liste_membre[i].nom, m.nom) == 0)&&(strcmp(total.liste_membre[i].prenom, m.prenom) == 0)){ //compare le noms d'auteurs de deux livres
            return 1;
        }
    }
    return 0;
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
    printf("Metier : %s\n",total.liste_membre[id_membre].metier);
    for (int i = 0; i < total.liste_membre[id_membre].n_livre_emprunt; ++i) {
        printf("Livre emprunter n %d\n",i);
        printf("code : ");
        dispCode(total.liste_membre[id_membre].liste_pret_membre[i].code);
        printf("\ndate d'emprunt : %d/%d/%d\n", total.liste_membre[id_membre].liste_pret_membre[i].date_pret.jour, total.liste_membre[id_membre].liste_pret_membre[i].date_pret.mois, total.liste_membre[id_membre].liste_pret_membre[i].date_pret.annee);
        printf("date de retour : %d/%d/%d\n", total.liste_membre[id_membre].liste_pret_membre[i].de_retour.jour, total.liste_membre[id_membre].liste_pret_membre[i].de_retour.mois, total.liste_membre[id_membre].liste_pret_membre[i].de_retour.annee);

    }
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


/*///////////////////////////////////////TRIER MEMBRE/////////////////////////////////////////////////////////////////*/

void trie_nom(){
    membre temp;
    for (int i = 0; i < total.n_membre; ++i) {
        for (int j = 0; j < total.n_membre; ++j){
            if (strcmp(total.liste_membre[i].nom, total.liste_membre[j].nom)<0){
                temp = total.liste_membre[i];
                total.liste_membre[i] = total.liste_membre[j];
                total.liste_membre[j] = temp;
            }
        }

    }

}
void trie_prenom(){
    membre temp;
    for (int i = 0; i < total.n_membre; ++i) {
        for (int j = 0; j < total.n_membre; ++j){
            if (strcmp(total.liste_membre[i].prenom, total.liste_membre[j].prenom)<0){
                temp = total.liste_membre[i];
                total.liste_membre[i] = total.liste_membre[j];
                total.liste_membre[j] = temp;
            }
        }

    }

}

void trie_membre(){
    int choice;
    do {
        printf("choisissez le type d'affichage\n");
        printf("    -1 pour le tri par nom\n");
        printf("    -2 pour le tri par prenom\n");
        printf("    -0 pour quitter le menu\n");
        scanf("%d",&choice);
    }while (choice !=1 && choice !=2 && choice !=0);
    if (choice == 1){
        trie_nom();
    } else if(choice == 2){
        trie_prenom();
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

/*///////////////////////////////////////GESTION PRET LIVRE///////////////////////////////////////////////////////////*/

void add_pret(int id_membre, int id_livre){

    date emprunt;
    printf("Rentrer la date d'emprunt du Livre : ");
    printf("\nJour : ");
    scanf("%d", &emprunt.jour);
    printf("\nMois : ");
    scanf("%d", &emprunt.mois);
    printf("\nAnnee : ");
    scanf("%d", &emprunt.annee);

    date rendu;
    printf("Rentrer la date a laquelle le livre doit etre rendu : ");
    printf("\nJour : ");
    scanf("%d", &rendu.jour);
    printf("\nMois : ");
    scanf("%d", &rendu.mois);
    printf("\nAnnee : ");
    scanf("%d", &rendu.annee);

    total.liste_membre[id_membre].liste_pret_membre[total.liste_membre[id_membre].n_livre_emprunt].date_pret = emprunt;
    total.liste_membre[id_membre].liste_pret_membre[total.liste_membre[id_membre].n_livre_emprunt].de_retour = rendu;
    total.liste_membre[id_membre].liste_pret_membre[total.liste_membre[id_membre].n_livre_emprunt].code = total.liste_livre[id_livre].code;
    total.liste_membre[id_membre].n_livre_emprunt++;


}

void ajouter_un_emprunt(){

    //PARTIE MEMBRE QUI VEUT EMPRUNTER
    int trie_membre_choice;
    do {
        printf("\nChoisissez un membre parmis la liste (0-trier par nom, 1-trier par prenoom)");
        scanf("%d", &trie_membre_choice);
    }while (trie_membre_choice!=0 && trie_membre_choice!=1);

    if (trie_membre_choice == 0){
        trie_nom();
    } else{
        trie_prenom();
    }

    afficher_all_membre();

    int choice_membre;
    printf("\nChoisir un id de membre : ");
    scanf("%d",&choice_membre);

    if (total.liste_membre[choice_membre].n_livre_emprunt<3) {
        //PARTIE LIVRE A EMPRUNTER
        int trie_livre_choice;
        do {
            printf("\nChoisissez un livre parmis la liste (0-trier par Theme, 1-trier par auteur)");
            scanf("%d", &trie_livre_choice);
        } while (trie_livre_choice != 0 && trie_livre_choice != 1);
        /*
        if (trie_livre_choice == 0){
            trie_nom();
        } else{
        trie_prenom();
        }
        */

        afficher_all_livre();
        int choice_livre;
        printf("\nChoisir un id de livre : ");
        scanf("%d", &choice_livre);

        add_pret(choice_membre, choice_livre);
    } else{
        printf("\n L'utilisateur a emprunter trop de livre");
    }
}

void suppr_emprunt(){
    int choice;
    do{
        printf("1-Chercher un membre en particulier  2-afficher tout les membres");
        fflush(stdin);
        scanf("%d", &choice);

    }while (choice !=1 && choice !=2);
    if (choice == 1){
        //cherche_membre();
    } else{
        trie_membre();
    }
    printf("choisissez le membre : ");
    int id;
    fflush(stdin);
    scanf("%d", &id);
    afficher_membre(id);
    int choice_suppr;
    do{
        printf("choisissez pres a enlever 4 pour annuler : ");
        fflush(stdin);
        scanf("%d", &choice_suppr);
    }while (choice_suppr< 0 || choice_suppr>4);

}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/