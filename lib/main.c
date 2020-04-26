#include "ShareThings.h"

int main(){
    char mdpAdmin[10];
    printf("Entrer mdp Admin :\n");
    scanf("%s", mdpAdmin);
    int menu;
    menu = menuAccueil();
    switch (menu) {
        case 1:
            while(! authentificationAdmin(mdpAdmin)){
                authentificationAdmin(mdpAdmin);
            }
            
            break;
        case 2:
            while(! authentificationClient(mdpAdmin)){
                authentificationClient(mdpAdmin);
            }
            menuDemandeurPreteur();
        default:
            menuAccueil();
            break;
    }
}
