#include <stdio.h>
#include <stdlib.h>
#include "store.h"


int main(int argc, char *argv[]){


    Date dtf = {0,0,0};
    Date dtp = {1,1,1};
    Lot lot = {"0", dtf, dtp};

    Medicament medoc1 = {0,"lab0","medicament0", 100, 2, 0, lot};
    Liste *maListe = initialisation();

    insertion(maListe, medoc1);
    insertion(maListe, medoc1);
    insertion(maListe, medoc1);
    suppression(maListe);

    afficherListe(maListe);

    return 0;
}