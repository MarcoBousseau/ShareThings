#include "ShareThings.h"

int main(){
    // RECUPERATION DES DONNEES
    
    
    // ACCES AUX MENUS ET DEPLACEMENT EN LEUR SEIN
    int menu;
    menu = menuAccueil();
    switch (menu) {
        case 1:
            int test = 0;
            while(! test){
                test = authentificationAdmin(mdpAdmin);
            }
            int saisieAdmin;
            saisieAdmin = menuAdmin();
            switch (saisieAdmin) {
                case 1:
                    Personne PersAjout;
                    PersAjout = creerPersonne();
                    
            }
            break;
        case 2:
            int test = 0;
            while(! test){
                test = authentificationAdmin(mdpAdmin);
            }
            fMenu
            break;
        case 3:
            saveClients(/*listeclients lc*/);
            saveRessources(/*TtesRessources tr*/);
        default:
            menuAccueil();
            break;
    }
}

int main(){
    
}
