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
    printf("\n---menu---\n");
    printf(" 1:  Ajouter un nouveau medicament\n");
    printf(" 2:  Afficher le numero d'un medicament (saisir le nom)\n");
    printf(" 3:  Afficher la liste de medicaments en stock\n");
    printf(" 4:  Afficher les informations d'un medicament grace a son numero\n");
    printf(" 5:  Afficher la liste de medicament dont le nom commence par une chaine donnee\n");
    printf(" 6:  Afficher tous les medicaments en rupture de stock\n");
    printf(" 7:  Afficher la quantite disponible d'un medicament\n");
    printf(" 8:  Afficher tous les fournisseurs d'un medicament\n");
    printf(" 9:  Servir une ordonnance\n");
    printf(" 1O: Afficher les medicaments perimes\n");
    printf(" 11: Supprimer un medicament\n");
    printf(" 12: Sauvegarder la liste de medicament dans un fichier --FMED--\n");
    printf(" 0:  Quitter\n");
    printf("Tapez un numero entre 1 a 12 ou 0 pour quitter:");
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
    drug->lt = lt;
    id++;
}

Medicament createDrug(char lab[], char nomM[], float px, int QStock, int S_stc, Lot lt){

    Medicament *drug = malloc(sizeof(*drug));
    drug->numM = id;
    strcpy(drug->lab, lab);
    strcpy(drug->nomM, nomM);
    drug->px = px;
    drug->Qstock = QStock;
    drug->S_stc = S_stc;
    drug->lt = lt;
    Fournisseur tempFournisseur = createFournisseur(0, "NULL", "NULL");
    drug->fr1 = tempFournisseur;
    drug->fr2 = tempFournisseur;
    drug->fr3 = tempFournisseur;
    drug->fr4 = tempFournisseur;
    drug->fr5 = tempFournisseur;
    id++;
    return *drug;
}

// Retourne un la date créé
Date createDate(int jr, int mo, int an){
    Date *date = malloc(sizeof(*date));
    date->an = an;
    date->mo = mo;
    date->jr = jr;
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
int initId() {
    FILE *folder = NULL;

    folder = fopen("db/id.txt","r");

    if(folder == NULL)
        printf("File Error");

    char value[MAX_ID] = "";
    fgets(value, MAX_ID, folder);

    if(strcmp(value,"")){
        id = atoi(value);
        return id;
    }
    else{
        printf("%s", value);
        return -1;
    }

    fclose(folder);
}


// Affiche les fournisseurs d'un médicament
void  printProvider(Medicament *drug){
    if(strcmp(drug->fr1.nomF, "NULL") != 0)
        printf("Fournisseur1: %s\n", drug->fr1.nomF);
    if(strcmp(drug->fr2.nomF, "NULL") != 0)
        printf("Fournisseur2: %s\n", drug->fr2.nomF);
    if(strcmp(drug->fr3.nomF, "NULL") != 0)
        printf("Fournisseur3: %s\n", drug->fr3.nomF);
    if(strcmp(drug->fr4.nomF, "NULL") != 0)
        printf("Fournisseur4: %s\n", drug->fr2.nomF);
    if(strcmp(drug->fr5.nomF, "NULL") != 0)
        printf("Fournisseur5: %s\n", drug->fr5.nomF);
}