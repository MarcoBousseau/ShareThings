#include <pwd.h>
#include <unistd.h>
#include "ShareThings.h"

int menuAccueil(){
    printf("\t\tMENU\n\n\t\t(1)Administrateur\n\t\t(2)Client\n\t\t(3)Quitter\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}
