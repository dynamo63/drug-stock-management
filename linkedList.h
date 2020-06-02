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
int issetItem(List *list, Medicament drug);
void insertItem(List *list, Medicament *drug);
void deleteItem(List *list);
void printDrugs(List *list);
Medicament getDrugById(List *list, int id);
Medicament getDrugByName(List *list, char name);
char *displayDrug(const Medicament *drug, char *buffer);

// Sauvegarde la liste dans fichier FMED.txt
void save(List *list);

#endif
