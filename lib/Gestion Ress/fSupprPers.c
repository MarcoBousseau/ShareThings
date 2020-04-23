#include "fSupprPers.h"
#include "ShareThings.h"

int supprPersonne(ListeClients lc, Personne *p1) {
    Personne *persactuelle = lc->head;
    while ((persactuelle->identifiant != p1->identifiant) && (persactuelle != lc->tail)) {
        persactuelle = persactuelle->suivant
    }
    
    if ((lc->head == NULL) || (persactuelle == lc->tail)) {
        if (persactuelle->identifiant == p1->identifiant) {
            Personne *p = lc->tail;
            lc->tail = (lc->tail)->precedent;
            free(p);
            lc->size--;
        }
        else {
            return 1;                                               //La personne à supprimer n'existe pas.
        }
    }
    
    else {
        (persactuelle->precedent)->suivant = persactuelle->suivant;
        free(persactuelle);
        lc->size--;
    }
    
    return 0;
}
