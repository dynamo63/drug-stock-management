#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "store.h"
#include "linkedList.h"


// Initie la liste chaînée
List *initList(Medicament *drug)
{
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Medicament medoc;
    // initMedicament(&medoc);
    item->medicament = *drug;
    item->next = NULL;
    list->first = item;

    return list;
}

// Initie la liste chaînée
List *initListByFile(Medicament *drug, FILE *FMED)
{
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    // Medicament medoc;
    // initMedicament(&medoc);
    item->medicament = *drug;
    item->next = NULL;
    list->first = item;

    return list;
}

// Vérifie si la liste contient déja le médicament
int containItem(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;

    while(actuel != NULL && actuel->medicament.numM != drug.numM){
        actuel = actuel->next;
    }
    
    if(actuel != NULL){
        return true;
    }else{
        return false;
    }
}
// Vérifie si la liste contient déja le médicament
int containRefLot(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;
    while(actuel != NULL && *actuel->medicament.lt.ref != *drug.lt.ref){
        actuel = actuel->next;
    }
    
    if(actuel != NULL){
        return true;
    }else{
        return false;
    }
}

// Insère un Medicament en début de liste
void insertItem(List *list, Medicament *drug)
{
    printf("J'insère le médicament %s\n", drug->nomM);
    /* Création du nouvel élément */
    Item *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if(containItem(list, *drug) && containRefLot(list, *drug)){
        listIncrement(list, *drug);
    }else{
        new->medicament = *drug;
        /* Insertion de l'élément au début de la list */
        new->next = list->first;
        list->first = new;
    }
}

//Incrémente un médicament dans la liste
void listIncrement(List *list, Medicament drug){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *actuel = list->first;
    while(actuel != NULL && actuel->medicament.numM != drug.numM){
        actuel = actuel->next;
    }
    if(actuel != NULL){
        actuel->medicament.Qstock = actuel->medicament.Qstock + 1;
    }
}

// Suprime le premier élément de la liste
void deleteItem(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Item *aSupprimer = list->first;
        list->first = list->first->next;
        free(aSupprimer);
    }
}


// Afiche la liste des médicaments
void printDrugs(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL)
    {
        char buffer[200];   
        printf("%s", displayDrug(&current->medicament, buffer));
        current = current->next;
    }
}

// Afiche la liste des médicaments en repture de stock
void printDrugsOff(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL)
    {
        char buffer[200];
        if(current->medicament.Qstock == 0){
            printf("%s", displayDrug(&current->medicament, buffer));
        }
        current = current->next;
    }
}

// Afiche la liste des médicaments commençant par un nom
void printDrugsWithName(List *list, char *name)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *current = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------");
    printf("\nNum\tNom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    while (current != NULL){
        char buffer[200];
        if(startWith(current->medicament.nomM, name)){
            printf("%s", displayDrug(&current->medicament, buffer));
        }
        current = current->next;
    }
}

//  Vérifie sous la chaine commence par la sous-chaine
int startWith(char *string, char *subString){
    int sousChainePointer;
    if(strstr(string, subString) != NULL){
        sousChainePointer = *(strstr(string, subString));
        if(*string == sousChainePointer){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

// Retourne un Médicament grace à son numéro
Medicament getDrugById(List *list, int id){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;

    while (actuel != NULL && actuel->medicament.numM != id){
        actuel = actuel->next;
    }

    if(actuel == NULL)
    {
        Medicament drug;
        initMedicament(&drug);
        return drug;
    }
    else
        return actuel->medicament;
    
}

// Retourne un Médicament grace à son nom
Medicament getDrugByName(List *list, char *name){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;
    while (actuel != NULL && strcmp(actuel->medicament.nomM, name) != 0){
        actuel = actuel->next;
    }

    if(actuel == NULL)
    {
        Medicament drug;
        initMedicament(&drug);
        return drug;
    }
    else
        return actuel->medicament;
    
}
    
//  Affiche les informations sur un médicament
char *displayDrug(const Medicament *drug, char *buffer){
    char dateFormated[40];
    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%f\t%d\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, dateFormated, drug->px, drug->Qstock);

    return buffer;
}

//  Affiche toutes les informations sur un médicament
char *displayDrugAll(const Medicament *drug, char *buffer){
    char dateFormated[40], fr1Formated[1000], fr2Formated[1000], fr3Formated[1000], fr4Formated[1000], fr5Formated[1000];
    if(drug->fr1.nomF != "")
        sprintf(fr1Formated, "[%s--%s--%d]", drug->fr1.nomF, drug->fr1.adr, drug->fr1.tel);
    else
        sprintf(fr1Formated, "NULL");
    if(drug->fr2.nomF != "")
        sprintf(fr2Formated, "[%s--%s--%d]", drug->fr2.nomF, drug->fr2.adr, drug->fr2.tel);
    else
        sprintf(fr2Formated, "NULL");
    if(drug->fr3.nomF != "")
        sprintf(fr3Formated, "[%s--%s--%d]", drug->fr3.nomF, drug->fr3.adr, drug->fr3.tel);
    else
        sprintf(fr3Formated, "NULL");
    if(drug->fr4.nomF != "")
        sprintf(fr4Formated, "[%s--%s--%d]", drug->fr4.nomF, drug->fr4.adr, drug->fr4.tel);
    else
        sprintf(fr4Formated, "NULL");
    if(drug->fr5.nomF != "")
        sprintf(fr5Formated, "[%s--%s--%d]", drug->fr5.nomF, drug->fr5.adr, drug->fr5.tel);
    else
        sprintf(fr5Formated, "NULL");

    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%f\t%d\t\t%s\t%s\t%s\t%s\t%s\t\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, dateFormated, drug->px, drug->Qstock, fr1Formated, fr2Formated, fr3Formated, fr4Formated, fr5Formated);
    return buffer;
}

//Sauvegarde le fichier dans le liste de fichier
void save(List *list) {
    if (list == NULL)
        exit(EXIT_FAILURE);

    FILE *folderFMED = NULL, *folderID = NULL;

    folderFMED = fopen("db/FMED.txt", "w+");
    folderID = fopen("db/id.txt", "w");

    if (folderFMED == NULL)
        exit(EXIT_FAILURE);

    Item *item = list->first;

    do{
        char buffer[200];
        fprintf(folderFMED,"%s", displayDrugAll(&item->medicament, buffer));
        item = item->next;
    }while (item->next != NULL);

    // Sauvegarde du dernier item ainsi que l'id
    char buf[200];
    fprintf(folderFMED,"%s", displayDrugAll(&item->medicament, buf));
    fprintf(folderID, "%d", item->medicament.numM);

    
    fclose(folderFMED);
    fclose(folderID);
}

// Ajoute un médicament à la liste
void ajouterMed(List *list){
    Medicament *tempMedicament = malloc(sizeof(*tempMedicament));
    tempMedicament->numM = initId();
    int nombreFournisseur;
    // printf("Nom: ");
    // scanf("%s", tempMedicament->nomM);
    // printf("Laboratoire: ");
    // scanf("%s", tempMedicament->lab);
    // printf("Prix du medicament: ");
    // scanf("%d", tempMedicament->px);
    // printf("Reférence du lot: ");
    // scanf("%s", tempMedicament->lt.ref);
    // printf("Numéro du secteur de stockage: ");
    // scanf("%d", &tempMedicament->S_stc);
    // printf("Quantité du médicament à ajouter: ");
    // scanf("%d", &tempMedicament->Qstock);
    // printf("\n---Date de fabrication---\n\n");
    // printf("Jour de fabrication: ");
    // scanf("%d", &tempMedicament->lt.dtf.jr);
    // printf("Mois de fabrication: ");
    // scanf("%d", &tempMedicament->lt.dtf.mo);
    // printf("Année de fabrication: ");
    // scanf("%d", &tempMedicament->lt.dtf.an);
    // printf("\n---Date de peremption---\n\n");
    // printf("Jour de peremption: ");
    // scanf("%d", &tempMedicament->lt.dtf.jr);
    // printf("Mois de peremption: ");
    // scanf("%d", &tempMedicament->lt.dtp.mo);
    // printf("Année de peremption: ");
    // scanf("%d", &tempMedicament->lt.dtp.an);
    // insertItem(list, tempMedicament);
    // printf("Nombre de fournisseur: ");
    // scanf("%d", &nombreFournisseur);

    

    // Date datetf = createDate(tempMedicament->lt.dtf.jr,tempMedicament->lt.dtf.mo,tempMedicament->lt.dtf.an);
    // Date datetp = createDate(tempMedicament->lt.dtp.jr, tempMedicament->lt.dtp.mo, tempMedicament->lt.dtp.an);
    // Lot lot = createLot(tempMedicament->lt.ref, datetf, datetp);
    // Medicament drug = createDrug(tempMedicament->lab, tempMedicament->nomM, tempMedicament->px, tempMedicament->Qstock, tempMedicament->S_stc, tempMedicament->lt);

    Date datetf = createDate(3,3,2017);
    Date datetp = createDate(3,3,2022);
    Lot lot = createLot("Lot-saint", datetf, datetp), lot2 = createLot("Lot2", datetf, datetp);
    Medicament drug = createDrug("labo-saint", "test", 20.000, 0, 2, lot);
    nombreFournisseur = 1;

    if(nombreFournisseur > 0){
        printf("Nom du fournisseur 1: ");
        scanf("%s", drug.fr1.nomF);
        printf("Adresse du fournisseur 1: ");
        scanf("%s", drug.fr1.adr);
        printf("Numero de telephone du fournisseur 1: ");
        scanf("%d", &drug.fr1.tel);
    }
    if(nombreFournisseur > 1){
        printf("\\nNom du fournisseur 2: ");
        scanf("%s", drug.fr2.nomF);
        printf("Adresse du fournisseur 2: ");
        scanf("%s", drug.fr2.adr);
        printf("Numero de telephone du fournisseur 2: ");
        scanf("%d", &drug.fr3.tel);
    }
    if(nombreFournisseur > 2){
        printf("\\nNom du fournisseur 3: ");
        scanf("%s", drug.fr3.nomF);
        printf("Adresse du fournisseur 3: ");
        scanf("%s", drug.fr3.adr);
        printf("Numero de telephone du fournisseur 3: ");
        scanf("%d", &drug.fr3.tel);
    }
    if(nombreFournisseur > 4){
        printf("\\nNom du fournisseur 4: ");
        scanf("%s", drug.fr4.nomF);
        printf("Adresse du fournisseur 4: ");
        scanf("%s", drug.fr4.adr);
        printf("Numero de telephone du fournisseur 4: ");
        scanf("%d", &drug.fr4.tel);
    }
    if(nombreFournisseur > 4){
        printf("\\nNom du fournisseur 5: ");
        scanf("%s", drug.fr5.nomF);
        printf("Adresse du fournisseur 5: ");
        scanf("%s", drug.fr5.adr);
        printf("Numero de telephone du fournisseur 5: ");
        scanf("%d", &drug.fr5.tel);
    }

    printf("Le fournisseur 1 est %s", drug.fr1.nomF);
    
    insertItem(list, &drug);
}
