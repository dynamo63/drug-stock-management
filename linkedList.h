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
void deleteItem(List *list);
void printDrugs(List *list);

#endif
