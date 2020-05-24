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
            printf("*******************************************************************\n");
            printf("                       BIENVENUE DANS LA BIBLIOTHEQUE\n");
            printf("*******************************************************************\n\n\n");
            printf("choisissez l'acces souhaite: \n");
            printf("1 - Acces lecture seul\n");
            printf("2 - Acces Interface bibliothecaire\n");
            printf("3 - quitter");
            fflush(stdin);
            scanf("%d", &choice_lecture_interface);
            system("cls");
        }while (choice_lecture_interface != 1 && choice_lecture_interface!=2 && choice_lecture_interface!=3);

        system("cls");
        if(choice_lecture_interface == 1){
            int choix_lecture;
            do{
                printf("choisissez l'acces souhaite: \n");
                printf("1 - Liste des membres classes\n");
                printf("2 - Listes des livres classes\n");
                printf("3 - Rechercher un livre en particulier\n");
                printf("4 - Afficher toutes les listes emprumter\n");
                printf("5 - Revenir en arriere\n");
                fflush(stdin);
                scanf("%d", &choix_lecture);
            }while (choix_lecture < 1 || choix_lecture > 5);
            system("cls");
            switch (choix_lecture) {
                case 1:{
                    trie_membre();
                    afficher_all_membre();
                    save();
                    system("pause");
                    system("cls");
                    break;
                }
                case 2:{
                    dispListeLivres();
                    save();
                    system("pause");
                    system("cls");
                    break;
                }
                case 3:{
                    menuRecherche();
                    save();
                    system("pause");
                    system("cls");
                    break;
                }
                case 4:{
                    afficher_emprumt();
                    save();
                    system("pause");
                    system("cls");
                    break;
                }
                default:{

                }
            }


        } else if(choice_lecture_interface == 2){
            int choix_interface;
            do{
                printf("choisissez l'acces souhaite: \n");
                printf("1 - Ajouter un nouveau membre\n");
                printf("2 - Ajouter un nouveau livres\n");
                printf("3 - supprimer un adherent\n");
                printf("4 - Enregistrer un nouvel emprumt\n");
                printf("5 - Restituer un livre emprunter\n");
                printf("6 - Revenir en arriere\n");
                fflush(stdin);
                scanf("%d", &choix_interface);
            }while (choix_interface < 1 || choix_interface > 6);

            system("cls");
            switch (choix_interface) {
                case 1:{
                    ajout_membre();
                    save();
                    system("cls");
                    break;
                }
                case 2:{
                    ajout_livre();
                    save();
                    system("cls");
                    break;
                }
                case 3:{
                    delete_membre();
                    save();
                    system("cls");
                    break;
                }
                case 4:{
                    ajouter_un_emprunt();
                    save();
                    system("cls");
                    break;
                }
                case 5:{
                    suppr_emprunt();
                    save();
                    system("cls");
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