#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "store.h"
#include <string.h>
#include <stdbool.h>


int main(int argc, char *argv[]){
    initId();
    Date datetf = createDate(3,3,2017);
    Date datetp = createDate(3,3,2025);
    Date datetp2 = createDate(9,6,2020);
    Lot lot = createLot("Lot-saint", datetf, datetp), lot2 = createLot("Lot2", datetf, datetp2);
    Fournisseur fournisseur1 = createFournisseur(91611135, "Laboratoire PERFECT-LABO", "Perfect");
    Fournisseur fournisseur2 = createFournisseur(91611135, "Laboratoire Lamboni-LABO", "Lamboni");
    Medicament medoc1 = createDrug("labo-saint", "Albert", 20.000, 10, 2, lot);
    Medicament medoc2 = createDrug("labo-saint", "Albertine", 20.000, 10, 2, lot2);
    Medicament medoc3 = createDrug("labo-saint", "Thérésa", 20.000, 10, 2, lot);
    Medicament medoc4 = createDrug("labo-saint", "Clémentine", 20.000, 10, 2, lot2);
    medoc4.fr1 = fournisseur2;
    List *maListe = initList(&medoc1);
    insertItem(maListe, &medoc2);
    insertItem(maListe, &medoc3);
    insertItem(maListe, &medoc4);
    
    
    int choix = -1, nbMED;
    char drugName[20], buffer[200];
    Medicament tempDrug;
    system("clear");
    while(choix){
        switch(choix){
            case(0):
                printf("Good Bye\n");
                break;

            case(1):
                printf("[Ajouter un nouveau medicament]\n\n");
                printf("\nCombien de médicament à ajouter?:");
                scanf("%d",&nbMED);
                for(int i=1; i<=nbMED; i++){
                    printf("\nAjout du médicament Numero %d\n\n", i);
                    ajouterMed(maListe);
                }
                break;

            case(2):
                printf("\n[Affichage le numero d'un medicament grace a son nom]\n");
                    printf("Veuillez saisir le nom : ");
                    scanf("%s",drugName);
                    tempDrug = getDrugByName(maListe, drugName);

                    if(strcmp(tempDrug.nomM, "MedicamentNull") == 0){
                        printf("Medicament inconnu\n\n");
                    }else{
                        printf("Le numéro du médicament %s est %d\n", tempDrug.nomM, tempDrug.numM);
                    }
                break;

            case(3):
                printf("\n[Affichage de la liste de medicaments en stock]\n");
                printDrugs(maListe);
                break;

            case(4):
                printf("\n[Affichage des informations d'un medicament grace a son numero]\n");
                printf("Veuiller saisir le numero du medicament: ");
                scanf("%d",&nbMED);
                tempDrug = getDrugById(maListe, nbMED);

                if(strcmp(tempDrug.nomM, "MedicamentNull") == 0){
                    printf("Médicament inconnu\n\n");
                }else{
                    printf("---------------------------------------------------------------------------------------------------------------------------");
                    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
                    printf("------------------------------------------------------------------------------------------------------------------------]\n");
                    printf("%s", displayDrug(&tempDrug, buffer));
                }
                break;

            case(5):
                printf("\n[Affichage de la liste des medicaments dont le nom commence par une chaine donnee]\n");
                printf("\nVeuiller saisir le mot clé: ");
                scanf("%s", drugName);
                printDrugsWithName(maListe, drugName);
                break;

            case(6):
                printf("\n[Affichage de la liste de medicaments en rupture de stock]\n");
                printDrugsOff(maListe);
                break;

            case(7):
                printf("\n[Affichage la quantité disponible d'un medicament]\n");
                printf("Veuiller saisir le numero du medicament: ");
                scanf("%d",&nbMED);
                tempDrug = getDrugById(maListe, nbMED);
                if(strcmp(tempDrug.nomM, "MedicamentNull") == 0){
                    printf("Médicament inconnu!!!\n\n");
                }else{
                    printf("La quantité restante du médicament %s est %d\n", tempDrug.nomM, tempDrug.Qstock);
                }
                break;

            case(8):
                printf("\n[Affichage des fournisseurs d'un medicament]\n");
                printf("Veiller saisir le numero du medicament: ");
                scanf("%d", &nbMED);
                tempDrug = getDrugById(maListe, nbMED);
                if(strcmp(tempDrug.nomM, "MedicamentNull") == 0){
                    printf("Médicament inconnu!!\n\n");
                }else{
                    system("clear");
                    printf("[Liste des fournisseur du médicament %s]\n", tempDrug.nomM);
                    printProvider(&tempDrug);
                }
                break;

            case(9):
                printf("\n[Affichage de la liste de medicaments en stock]\n");
                printDrugs(maListe);
                printf("\nServir une ordonnance:\n");
                servePrescription(maListe);
                break;

            case(10):
                printf("\n[Affichage des medicaments périmés]\n");
                printExpiredDrugs(maListe);
                printf("\n");
                break;

            case(11):
                printf("\n[Affichage de la liste de medicaments en stock]\n");
                printDrugs(maListe);
                printf("\n[Supression d'un medicament grace a son numero]\n");
                printf("Veuiller saisir le numero du medicament: ");
                scanf("%d",&nbMED);
                deleteItem(maListe, nbMED);
                printf("\n");
                break;

            case(12):
                printf ("\n [Saugegarde de la liste des medicaments dans un fichier --FMED--]\n\n");
                save(maListe);
                break;
        }
        choix = menu();
        system("clear");
    }
    save(maListe);
    return 0;
}