#include "fSaveRess.h"
#include "ShareThings.h"

int saveRessources(TtesRessources tr) {     //sert a sauvegarder la liste des ressources.
    FILE* fichier = NULL;
    
    fichier = fopen("ressources.txt", "w");         //on ouvre le fichier dans lequel on va sauvegarder.
    
    if (fichier == NULL) {              //on verifie si le fichier a ete ouvert avec succes.
        printf("Impossible d'ouvrir le fichier ressources.txt");
        return 1;
    }
    
    else {
        Ressource ressactuelle = tr->head;
        Date rdate = NULL;
        
        while (ressactuelle != NULL) {      //la boucle sert a stocker toutes les ressources.
            rdate = ressactuelle->debut;
            
            fprintf(fichier, "%d\n", ressactuelle->type);           //on ecrit dans le fichier chaque donnee de chaque ressource a sauvegarder.
            fprintf(fichier, "%d\n", ressactuelle->disponible);
            fprintf(fichier, "%s\n", ressactuelle->Nom);
            fprintf(fichier, "%s\n", ressactuelle->idemprunteur);
            fprintf(fichier, "%s\n", ressactuelle->idproprietaire);
            if (rdate =! NULL) {                        //si la ressource a deja ete empruntee == si il y a une date de debut.
                fprintf(fichier, "%s\n", rdate->jour);
                fprintf(fichier, "%s\n", rdate->mois);
                fprintf(fichier, "%s\n", rdate->annee);
            }
            else {                      //si il n'y a pas de date de debut d'emprunt.
                fputs("n\n", fichier);
            }
            
            ressactuelle = ressactuelle->suivant;           //on passe a la ressource suivante afin de sauvegarder chaque ressource de la liste.
        }
    }
    return 0;
}

