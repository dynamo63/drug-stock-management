#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include <string.h>

int menu(void)
{
    int choix = 0;
    printf("---menu---\n\n");
    printf(" 1:  Ajouter un nouveau medicament \n\n");
    printf(" 2:  afficher le numero d'un medicament garce a son nom:\n\n");
    printf(" 3:  afficher la liste de medicaments en stock:\n\n");
    printf(" 4:  afficher les informations d'un medicament grace a son numero:\n\n");
    printf(" 5:  afficher la liste de medicament dont le nom commence par une chaine donn�e: \n\n ");
    printf(" 6:  afficher tous les medicaments en rupture de stock: \n\n");
    printf(" 7:  afficher la quantit� disponible d'un medicament: \n\n ");
    printf(" 8:  afficher tous les fournisseurs d'un medicament: \n\n ");
    printf(" 9:  servir une ordonnance: \n\n ");
    printf(" 1O: afficher les medicaments perim�s: \n\n ");
    printf(" 11: supprimer un medicament: \n\n ");
    printf (" 12: saugegarder la liste de medicament dans un fichier --FMED--\n\n");
    printf(" 0:  quitter\n\n");
    printf("Tapez un numero de 1 a 12 ou 0 pour quitter \n\n");
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
    drug->numM = rand();
    // drug->numM = 0;
    strcpy(drug->lab, "Lab0");
    strcpy(drug->nomM, "Medicament0");
    drug->px = 0.0;
    drug->Qstock = 0;
    drug->S_stc = 0;
    Lot lt;
    Fournisseur fr;
    initLot(&lt);
    initFournisseur(&fr);
    drug->lt = lt;
    drug->fr = fr;
}