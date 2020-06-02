#ifndef LINKEDLIST
#define LINKEDLIST

#include "store.h"
// Liste des médicaments
typedef struct Item Item;
struct Item
{
    Medicament medicament;
    Item *next;
};

typedef struct List List;
struct List
{
    Item *first;
};

List *initList();
void insertItem(List *list, Medicament drug);
void insertItemToMidle(List *list, Medicament *predDrug, Medicament newDrug);
void deleteItem(List *list);
void deleteItemToMidle(List *list, Medicament *aSuprimmer);
void printDrugs(List *list);
char *displayDrug(const Medicament *drug, char *buffer);

// Sauvegarde la liste dans fichier FMED.txt
void save(List *list);

#endif
