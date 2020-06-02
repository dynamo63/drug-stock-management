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

void printDrugs(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *actuel = list->first;

    printf("---------------------------------------------------------------------------------------------------------------------------\nNum\tNom\t\tLab\tRefLot\tDate Préemption\tPrix\t\tQuantité\n---------------------------------------------------------------------------------------------------------------------------\n");

    while (actuel != NULL)
    {
        char dateParsed[40];
        sprintf(dateParsed, "%d/%d/%d", actuel->medicament.lt.dtp.jr, actuel->medicament.lt.dtp.mo, actuel->medicament.lt.dtp.an);
        printf("%d\t%s\t%s\t%s\t%s\t%f\t%d\n", actuel->medicament.numM, actuel->medicament.nomM, actuel->medicament.lab, actuel->medicament.lt.ref, dateParsed, actuel->medicament.px, actuel->medicament.Qstock);
        actuel = actuel->next;
    }
}