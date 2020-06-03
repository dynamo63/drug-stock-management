#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "store.h"
#include "linkedList.h"


// Initie la liste chaînée
List *initList()
{
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
        exit(EXIT_FAILURE);

    Medicament medoc;
    initMedicament(&medoc);
    item->medicament = medoc;
    item->next = NULL;
    list->first = item;

    return list;
}

// Vérifie si la liste contient déja le médicament de meme nom
int containItem(List *list, Medicament *drug){
    if (list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel = list->first;

    while(actuel != NULL && strcmp(actuel->medicament.nomM, drug->nomM) != 0 && strcmp(actuel->medicament.lt.ref, drug->lt.ref) != 0)
    {
        actuel = actuel->next;
    }
    
    if(actuel != NULL)
        return true;
    else
        return false;
}


// Insère un Medicament en début de liste
void insertItem(List *list, Medicament *drug)
{
    /* Création du nouvel élément */
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
        exit(EXIT_FAILURE);

    if(containItem(list, drug))
    {
        Medicament *pt_drug = getDrugByName(list, drug->nomM);
        // char buf[200];
        // printf("%s", displayDrug(pt_drug, buf));
        if(strcmp(pt_drug->nomM, drug->nomM) == 0)
            pt_drug->Qstock++;
        pt_drug = NULL;
    }
    else
    {
        item->medicament = *drug;
        /* Insertion de l'élément au début de la list */
        item->next = list->first;
        list->first = item;
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

    printf("""---------------------------------------------------------------------------------------------------------------------------\nNum\tNom\t\tLab\tRefLot\tDate Préemption\tPrix\t\tQuantité\n---------------------------------------------------------------------------------------------------------------------------\n""");

    while (current != NULL)
    {
        char buffer[200];   
        printf("%s", displayDrug(&current->medicament, buffer));
        current = current->next;
    }
}

Medicament getDrugById(List *list, int id){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;

    while (actuel->next != NULL && actuel->medicament.numM != id){
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

Medicament *getDrugByName(List *list, char *name){
    if(list == NULL)
        exit(EXIT_FAILURE);

    Item *actuel  = list->first;

    while (actuel != NULL && strcmp(actuel->medicament.nomM, name)){
        actuel = actuel->next;
    }

    if(actuel == NULL)
        return &list->first->medicament;
    else
        return &actuel->medicament;
    
}
    
char *displayDrug(const Medicament *drug, char *buffer){
    char dateFormated[40];
    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%f\t%d\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, dateFormated, drug->px, drug->Qstock);

    return buffer;
}

void save(List *list) {
    if (list == NULL)
        exit(EXIT_FAILURE);

    FILE *folderFMED = NULL, *folderID = NULL;

    folderFMED = fopen("db/FMED.txt", "a");
    folderID = fopen("db/id.txt", "w");

    if (folderFMED == NULL)
        exit(EXIT_FAILURE);

    Item *item = list->first;

    do{
        char buffer[200];
        fprintf(folderFMED,"%s", displayDrug(&item->medicament, buffer));
        item = item->next;
    }while (item->next != NULL);

    // Sauvegarde du dernier item ainsi que l'id
    char buf[200];
    fprintf(folderFMED,"%s", displayDrug(&item->medicament, buf));
    fprintf(folderID, "%d", item->medicament.numM);

    
    fclose(folderFMED);
}