#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "linkedList.h"
#include <stdbool.h>


int main(int argc, char *argv[]){
    // initId();
    Date datetf = createDate(3,3,2010);
    Date datetp = createDate(3,3,2010);
    Lot lot, lot2;
    initLot(&lot);
    initLot(&lot2);
    sprintf(lot2.ref, "C3PO");
    Fournisseur fournisseur;
    initFournisseur(&fournisseur);

    Medicament medoc1 = createDrug("labo-saint", "Medicament1", 20.000, 5, 2, lot, fournisseur);
    Medicament medoc2 = createDrug("labo-saint", "Medicament2", 20.000, 5, 2, lot, fournisseur);
    Medicament medoc3 = createDrug("labo-saint", "Medicament3", 20.000, 5, 2, lot, fournisseur);
    Medicament medoc4 = createDrug("labo-saint", "Medicament4", 20.000, 5, 2, lot, fournisseur);
    Medicament medoc5 = createDrug("labo-saint", "Medicament4", 20.000, 5, 2, lot2, fournisseur);

    List *maListe = initList(&medoc1);
    insertItem(maListe, &medoc2);
    insertItem(maListe, &medoc3);
    insertItem(maListe, &medoc4);
    insertItem(maListe, &medoc4);
    insertItem(maListe, &medoc5);
    printDrugs(maListe);
    // system("clear");
    // save(maListe);
    return 0;
}