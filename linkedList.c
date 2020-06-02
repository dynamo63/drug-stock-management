#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "store.h"
#include "linkedList.h"

List *initList()
{
    List *list = malloc(sizeof(*list));
    Item *item = malloc(sizeof(*item));

    if (list == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Medicament medoc;
    initMedicament(&medoc);
    item->medicament = medoc;
    item->next = NULL;
    list->first = item;

    return list;
}

void insertItem(List *list, Medicament drug)
{
    /* Création du nouvel élément */
    Item *new = malloc(sizeof(*new));
    if (list == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->medicament = drug;

    /* Insertion de l'élément au début de la list */
    new->next = list->first;
    list->first = new;
}

void insertItemToMidle(List *list, Medicament *precDrug, Medicament newDrug){
    Item *new = malloc(sizeof(*new));
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->medicament = newDrug;
    Item *actuel = list->first;

    while(actuel != NULL && actuel->medicament.numM != precDrug->numM){
        actuel = actuel->next;
    }
    // si on a trouvé une corespondance, on ajoute l'élément
    if(actuel != NULL){
        new->next = actuel->next;
        actuel->next = new;
    }else{
        printf("L'element %s n'est pas dans la liste", precDrug->nomM);
    }
}

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

void deleteItemToMidle(List *list, Medicament *aSuprimmer){
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Item *prec = list->first, *actuel = list->first;

    while(actuel != NULL){
        prec = actuel;
        actuel = actuel->next;
        if(actuel->medicament.numM != aSuprimmer->numM){
            break;
        }
    }
    // si on a trouvé une corespondance, on ajoute l'élément
    if(actuel != NULL){
        prec->next = actuel->next;
        free(actuel);
    }else{
        printf("L'element %s n'est pas dans la liste", aSuprimmer->nomM);
    }
}

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

char *displayDrug(const Medicament *drug, char *buffer){
    char dateFormated[40];
    sprintf(dateFormated, "%d/%d/%d", drug->lt.dtp.jr, drug->lt.dtp.mo, drug->lt.dtp.an);
    sprintf(buffer,"%d\t%s\t%s\t%s\t%s\t%f\t%d\n",drug->numM, drug->nomM, drug->lab, drug->lt.ref, dateFormated, drug->px, drug->Qstock);

    return buffer;
}