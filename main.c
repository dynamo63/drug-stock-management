#include <stdio.h>
#include <stdlib.h>
#include "store.h"


int main(int argc, char *argv[]){
    Medicament medoc1;
    initMedicament(&medoc1);
    
    List *maListe = initList();
    
    insertItem(maListe, medoc1);
    deleteItem(maListe);
    printDrugs(maListe);
    return 0;
}