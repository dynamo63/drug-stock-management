#ifndef MINI_PROJET_H_INCLUDED
#define MINI_PROJET_H_INCLUDED

typedef struct{

    int jr;
    int mo;
    int an;
}Date;

typedef struct{

    int ref;
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

// Un Item de la liste de Medicament 
typedef struct Item Item;
struct Item{
    Medicament drug;
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


#endif // MINI_PROJET_H_INCLUDED

