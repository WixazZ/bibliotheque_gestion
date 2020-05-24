//
// Created by parad on 01/05/2020.
//
#include<stdio.h>
#include "fonction_membre.h"
#include "fonction_livre.h"

int main(){
    recup_data();
    int choice_lecture_interface = 0;

    while (choice_lecture_interface !=3 ){

        do{
            printf("1 - Acces lecture seul\n");
            printf("2 - Acces Interface bibliothécaire\n");
            printf("3 - quitter");
            fflush(stdin);
            scanf("%d", &choice_lecture_interface);
        }while (choice_lecture_interface != 1 && choice_lecture_interface!=2);


        if(choice_lecture_interface == 1){
            int choix_lecture;
            do{
                printf("1 - Liste des membres classés\n");
                printf("2 - Listes des livres classés\n");
                printf("3 - Rechercher un livre en particulier\n");
                printf("4 - Afficher toutes les listes emprumter\n");
                printf("5 - Revenir en arrière\n");
                fflush(stdin);
                scanf("%d", &choix_lecture);
            }while (choix_lecture < 1 || choix_lecture > 5);

            switch (choix_lecture) {
                case 1:{
                    trie_membre();
                    save();
                    break;
                }
                case 2:{
                    dispListeLivres();
                    save();
                    break;
                }
                case 3:{
                    menuRecherche();
                    save();
                    break;
                }
                case 4:{
                    afficher_emprumt();
                    save();
                    break;
                }
                default:{

                }
            }


        } else{
            int choix_interface;
            do{
                printf("1 - Ajouter un nouveau membre\n");
                printf("2 - Ajouter un nouveau livres\n");
                printf("3 - supprimer un adhérent\n");
                printf("4 - Enregistrer un nouvel emprumt\n");
                printf("5 - Restituer un livre emprunter\n");
                printf("6 - Revenir en arrière\n");
                fflush(stdin);
                scanf("%d", &choix_interface);
            }while (choix_interface < 1 || choix_interface > 6);


            switch (choix_interface) {
                case 1:{
                    ajout_membre();
                    save();
                    break;
                }
                case 2:{
                    ajout_livre();
                    save();
                    break;
                }
                case 3:{
                    delete_membre();
                    save();
                    break;
                }
                case 4:{
                    ajouter_un_emprunt();
                    save();
                    break;
                }
                case 5:{
                    suppr_emprunt();
                    save();
                    break;
                }
                default:{

                }
            }
        }

    }

    renvoie_data();

    return 0;
}