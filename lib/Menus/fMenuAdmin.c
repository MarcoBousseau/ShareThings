#include "ShareThings.h"
#include "fMenuAdmin.h"

int menuAdmin(){
    printf("\t\tMENU Administrateur\n\n\t\t(1)Ajouter Personne\n\t\t(2)Modifier les coordonnees d'une personne\n\t\t(3)Supprimer Personne\n\t\t(4)Afficher la liste des clients\n\t\t(5)Retour\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}
