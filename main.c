#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "linkedList.h"


int main(int argc, char *argv[]){

    initId();


    Medicament medoc1, medoc2, medoc3, medoc4;
    initMedicament(&medoc1);
    initMedicament(&medoc2);
    initMedicament(&medoc3);
    initMedicament(&medoc4);

    List *maListe = initList();
    
    insertItem(maListe, medoc1);
    insertItem(maListe, medoc3);
    insertItem(maListe, medoc4);
    insertItemToMidle(maListe, &medoc1, medoc2);
    deleteItemToMidle(maListe, &medoc3);
    
    printDrugs(maListe);

    return 0;
}