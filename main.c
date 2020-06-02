#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "linkedList.h"
#include <stdbool.h>


int main(int argc, char *argv[]){

    initId();

    Medicament medoc1, medoc2, medoc3, medoc4;
    initMedicament(&medoc1);
    initMedicament(&medoc2);
    initMedicament(&medoc3);
    initMedicament(&medoc4);


    List *maListe = initList();

    insertItem(maListe, &medoc1);
    insertItem(maListe, &medoc2);
    sprintf(medoc2.lt.ref, "001");
    insertItem(maListe, &medoc2);
    printf("%s\n", medoc2.lt.ref);
    insertItem(maListe, &medoc2);
    insertItem(maListe, &medoc2);
    printDrugs(maListe);
    
    // system("clear");

    // int choix=0, nbMED, nm, aa;



    save(maListe);

    return 0;
}