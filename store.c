#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include <string.h>
#include "store.h"
#define MAX_ID 1000

// Definition des variables d'environement
static int id = 0;


int menu(void)
{
    int choix = 0;
    printf("\n\n---menu---\n\n");
    printf(" 1:  Ajouter un nouveau medicament\n\n");
    printf(" 2:  afficher le numero d'un medicament (saisir le nom ):\n\n");
    printf(" 3:  afficher la liste de medicaments en stock:\n\n");
    printf(" 4:  afficher les informations d'un medicament grace a son numero:\n\n");
    printf(" 5:  afficher la liste de medicament dont le nom commence par une chaine donnee: \n\n");
    printf(" 6:  afficher tous les medicaments en rupture de stock: \n\n");
    printf(" 7:  afficher la quantite disponible d'un medicament: \n\n");
    printf(" 8:  afficher tous les fournisseurs d'un medicament: \n\n");
    printf(" 9:  servir une ordonnance: \n\n");
    printf(" 1O: afficher les medicaments perimes: \n\n");
    printf(" 11: supprimer un medicament: \n\n");
    printf(" 12: sauvegarder la liste de medicament dans un fichier --FMED--\n\n");
    printf(" 0:  quitter\n\n");
    printf("Tapez un numero de 1 a 12 ou 0 pour quitter:");
    scanf("%d",&choix);
    return choix;
}

void initDate(Date *date){
    date->an = 2020;
    date->jr = 1;
    date->mo = 1;
}

void initLot(Lot *lot){
    Date date;
    initDate(&date);
    strcpy(lot->ref, "Lot0");
    lot->dtf = date;
    lot->dtp = date;
}
void initFournisseur(Fournisseur *fr){
    fr->tel = 0;
    strcpy(fr->adr, "adresse");
    strcpy(fr->nomF, "nomF");
}

void initMedicament(Medicament *drug){
    drug->numM = id;
    // drug->numM = 0;
    strcpy(drug->lab, "Lab0");
    strcpy(drug->nomM, "MedicamentNull");
    drug->px = 0.0;
    drug->Qstock = 1;
    drug->S_stc = 1;
    Lot lt;
    Fournisseur fr;
    initLot(&lt);
    initFournisseur(&fr);
    FournisseurList frs;
    frs.f1 = fr;
    drug->lt = lt;
    drug->frs = frs;
    id++;
}

Medicament createDrug(char lab[], char nomM[], float px, int QStock, int S_stc, Lot lt, FournisseurList frs){
    // drug->numM = numM;
    Medicament *drug = malloc(sizeof(*drug));
    drug->numM = id;
    strcpy(drug->lab, lab);
    strcpy(drug->nomM, nomM);
    drug->px = px;
    drug->Qstock = QStock;
    drug->S_stc = S_stc;
    drug->lt = lt;
    drug->frs = frs;
    id++;
    return *drug;
}

// Retourne un la date créé
Date createDate(int jr, int mo, int an){
    Date *date = malloc(sizeof(*date));
    date->an = 2020;
    date->jr = 1;
    date->mo = 1;
    return *date;
}

// Retourne le lot créé
Lot createLot(char ref[], Date dtf, Date dtp){
    Lot *lot = malloc(sizeof(*lot));
    strcpy(lot->ref, ref);
    lot->dtf = dtf;
    lot->dtp = dtp;
    return *lot;
}

// Retourne le fournisseur créé
Fournisseur createFournisseur(int tel, char adr[], char nomF[]){
    Fournisseur *fr = malloc(sizeof(*fr));
    fr->tel = tel;
    strcpy(fr->adr, adr);
    strcpy(fr->nomF, nomF);
    return *fr;
}

// Initie l'identifiant
void initId() {
    FILE *folder = NULL;

    folder = fopen("db/id.txt","r");

    if(folder == NULL)
        printf("File Error");

    char value[MAX_ID] = "";
    fgets(value, MAX_ID, folder);

    if(strcmp(value,""))
        id = atoi(value);
    else
        printf("%s", value);

    fclose(folder);
}