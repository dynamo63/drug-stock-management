#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "linkedList.h"


int main(int argc, char *argv[]){


    Medicament medoc2;
    initMedicament(&medoc2);
    List *maListe = initList();
    insertItem(maListe, medoc2);
    deleteItem(maListe);

    printDrugs(maListe);

    return 0;
}