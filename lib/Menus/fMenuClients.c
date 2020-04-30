#include "fMenuClients.h"
#include "Menus/hMenus.h"

int menuClients(){
    printf("\t\tMENU CLIENTS\n\n\t\t(1)Recherche par type\n\t\t(2)Gerer mes ressources\n\t\t(3)Gerer mes informations personnelles\n\t\t(4)Retour\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}

