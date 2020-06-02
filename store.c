#include <stdio.h>
#include <stdlib.h>
#include "store.h"

int menu(void)
{
    int choix = 0;
    printf("---menu---\n\n");
    printf(" 1:  Ajouter un nouveau medicament \n\n");
    printf(" 2:  afficher le numero d'un medicament garce a son nom:\n\n");
    printf(" 3:  afficher la liste de medicaments en stock:\n\n");
    printf(" 4:  afficher les informations d'un medicament grace a son numero:\n\n");
    printf(" 5:  afficher la liste de medicament dont le nom commence par une chaine donn�e: \n\n ");
    printf(" 6:  afficher tous les medicaments en rupture de stock: \n\n");
    printf(" 7:  afficher la quantit� disponible d'un medicament: \n\n ");
    printf(" 8:  afficher tous les fournisseurs d'un medicament: \n\n ");
    printf(" 9:  servir une ordonnance: \n\n ");
    printf(" 1O: afficher les medicaments perim�s: \n\n ");
    printf(" 11: supprimer un medicament: \n\n ");
    printf (" 12: saugegarder la liste de medicament dans un fichier --FMED--\n\n");
    printf(" 0:  quitter\n\n");
    printf("Tapez un numero de 1 a 12 ou 0 pour quitter \n\n");
    scanf("%d",&choix);
    return choix;
}

Liste *initialisation()
{
    Liste *liste = malloc(sizeof(*liste));
    Item *item = malloc(sizeof(*item));

    if (liste == NULL || item == NULL)
    {
        exit(EXIT_FAILURE);
    }
    Date dtf = {0,0,0};
    Date dtp = {1,1,1};
    Lot lot = {"0", dtf, dtp};

    Medicament medoc1 = {0,"lab0","medicament0", 100, 2, 0, lot};
    item->medicament = medoc1;
    item->next = NULL;
    liste->first = item;

    return liste;
}

void insertion(Liste *liste, Medicament nvMedicament)
{
    /* Création du nouvel élément */
    Item *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->medicament = nvMedicament;

    /* Insertion de l'élément au début de la liste */
    nouveau->next = liste->first;
    liste->first = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->first != NULL)
    {
        Item *aSupprimer = liste->first;
        liste->first = liste->first->next;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Item *actuel = liste->first;

    printf("---------------------------------------------------------------------------------------------------------------------------\nNum Nom\tLab\tRefLot\tDate Préemption\tPrix\tQuantité\n---------------------------------------------------------------------------------------------------------------------------\n");

    while (actuel != NULL)
    {
        char dateParsed[40];
        sprintf(dateParsed, "%d/%d/%d", actuel->medicament.lt.dtp.jr, actuel->medicament.lt.dtp.mo, actuel->medicament.lt.dtp.an);
        printf("%d\t%s\t%s\t%s\t%s\t\t%f\t%d\n", actuel->medicament.numM, actuel->medicament.nomM, actuel->medicament.lab, actuel->medicament.lt.ref, dateParsed, actuel->medicament.px, actuel->medicament.Qstock);
        actuel = actuel->next;
    }
    printf("NULL\n");
}