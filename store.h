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

typedef struct {
    Fournisseur f1;
    Fournisseur f1;
    Fournisseur f3;
    Fournisseur f4;
    Fournisseur f5;
}FournisseurList;

typedef struct{

    int numM;
    char lab[20];
    char nomM[30];
    float px;
    int Qstock;
    int S_stc;
    Lot lt;
    FournisseurList frs;

}Medicament;

// fonction utilitaire
int menu();

void initDate(Date *date);
Date createDate(int jr, int mo, int an);
void initLot(Lot *lot);
Lot createLot(char ref[], Date dtf, Date dtp);
void initFournisseur(Fournisseur *fr);
Fournisseur createFournisseur(int tel, char adr[], char nomF[]);
void initMedicament(Medicament *drug);
Medicament createDrug(char labnomM[], char nomM[], float px, int QStock, int S_stc, Lot lt, FournisseurList frs);
void initId();
#endif // MINI_PROJET_H_INCLUDED

