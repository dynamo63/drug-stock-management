#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "linkedList.h"
#include <stdbool.h>


int main(int argc, char *argv[]){

    initId();

    Medicament medoc1, medoc2, medoc3, medoc4;
    initMedicament(&medoc1);
    sprintf(medoc1.nomM, "Medicament1");
    initMedicament(&medoc2);
    sprintf(medoc2.nomM, "Medicament2");
    initMedicament(&medoc3);
    sprintf(medoc3.nomM, "Medicament3");
    initMedicament(&medoc4);
    sprintf(medoc4.nomM, "Medicament4");


    List *maListe = initList();

    insertItem(maListe, &medoc1);
    insertItem(maListe, &medoc1);
    insertItem(maListe, &medoc2);
    sprintf(medoc2.lt.ref, "C3PO");
    insertItem(maListe, &medoc2);
    insertItem(maListe, &medoc2);
    insertItem(maListe, &medoc2);
    printDrugs(maListe);
    
    // system("clear");

    // save(maListe);

    // int choix=0, nbMED, nm, aa;



    save(maListe);

    return 0;
}