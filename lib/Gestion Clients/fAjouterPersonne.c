#include "fAjouterPersonne.h"
#include <stdio.h>

int ajouterPersonne(ListeClients lc, Personne *p1) {
    p1 = (Personne *)malloc(sizeof(Personne));
    
    if (lc->size == 0) {
        lc->head = p1;
        lc->tail = p1;
    }
    
    else {
        (lc->tail)->suivant = p1;
        p1->precedent = (lc->tail);
        lc->tail = p1;
    }
    lc->size++;
    return 0;
}
