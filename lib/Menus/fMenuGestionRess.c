#include "fMenuGestionRess.h"
#include "ShareThings.h"

int menuGestionRess(){
    printf("\t\tMENU CLIENTS\n\n\t\t(1)Nombre de Ressources pretees\n\t\t(2)Nombre de Ressources empruntees\n\t\t(3)Fin de pret\n\t\t(4)Liste des operations sur une periode\n\t\t(5)Supprimer une de mes ressources\n\t\t(6)Retour\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}

