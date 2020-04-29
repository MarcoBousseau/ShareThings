#include "fRechParType.h"
#include "GestionRess/hGestRess.h"

int rechercheParType(TtesRessources tr, int typerech) {
    if (tr->head == NULL) {
        printf("Aucune ressource de ce type a afficher.");
        return 1;                           //Aucune ressource à afficher.
    }
    
    Ressource *res = tr->head;
    char n;
    while (res != tr->tail) {
        if (res->type == typerech) {
            n = res->Nom;
            printf("%s\n", n);
        }
        res = res->suivant;
    }
    if ((tr->tail)->type == typerech) {
        n = res->Nom;
        printf("%s\n", n);
    }
    
    return 0;
}
