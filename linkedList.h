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

List *initList(Medicament *drug);
List *initListByFile(Medicament *drug, FILE *FMED);
int containItem(List *list, Medicament drug);
int containRefLot(List *list, Medicament drug);
void listIncrement(List *list, Medicament drug);
void insertItem(List *list, Medicament *drug);
void deleteItem(List *list);
void printDrugs(List *list);
void printDrugsOff(List *list);
void printDrugsWithName(List *list, char *name);
Medicament getDrugById(List *list, int id);
Medicament getDrugByName(List *list, char *name);
char *displayDrug(const Medicament *drug, char *buffer);
char *displayDrugAll(const Medicament *drug, char *buffer);
int startWith(char *string, char *subString);


// Sauvegarde la liste dans fichier FMED.txt
void save(List *list);
void ajouterMed(List *list);
#endif
