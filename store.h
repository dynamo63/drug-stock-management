#ifndef MINI_PROJET_H_INCLUDED
#define MINI_PROJET_H_INCLUDED

typedef struct{

    int jr;
    int mo;
    int an;
}Date;

typedef struct{

    char ref[10];
    Date dtf;
    Date dtp;
}Lot;



typedef struct {

    char nomF[20];
    char adr[30];
    int tel;
}Fournisseur;

typedef struct{

    int numM;
    char lab[20];
    char nomM[30];
    float px;
    int Qstock;
    int S_stc;
    Lot lt;
    Fournisseur fr;

}Medicament;

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

// fonction utilitaire
int menu();

List *initList();
void insertItem(List *list, Medicament drug);
void deleteItem(List *list);
void initDate(Date *date);
void initLot(Lot *lot);
void initFournisseur(Fournisseur *fr);
void initMedicament(Medicament *drug);
void printDrugs(List *list);



#endif // MINI_PROJET_H_INCLUDED

