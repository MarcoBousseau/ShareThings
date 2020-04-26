#include "fMenuGestionInfos.h"
#include "ShareThings.h"

int menuGestionInfos(){
    printf("\t\tMENU CLIENTS\n\n\t\t(1)Changer mon mot de passe\n\t\t(2)Changer mes coordonnes\n\t\t(3)Fin de pret\n\t\t(4)Liste des operations sur une periode\n\t\t(5)Supprimer mon compte\n\t\t(6)Retour\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}
