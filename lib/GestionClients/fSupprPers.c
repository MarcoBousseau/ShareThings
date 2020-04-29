#include "fSupprPers.h"
#include "GestionClients/hGestCli.h"

int supprPersonne(ListeClients lc, Personne *p1) {
    Personne actuel = lc->head;
    int i;
    int compt = 0;
    int res = 0;
    while ((actuel != NULL) && (compt != 30)) {
        for (i=0; i <= 29; i++) {
            if ((actuel->identifiant)[i] == p1[i]) {
                compt++;
            }
        }
        if (compt != 30) {
            compt = 0;
            actuel = actuel->suivant;
        }
    }
    
    if (actuel == NULL) {
        printf("L'identifiant rentré ne correspond à aucun client.");
        return 1;
    }
    else {
        //supprimer la personne "actuel"
        (actuel->precedent)->suivant = actuel->suivant;
        (actuel->suivant)->precedent = actuel->precedent;
        free(actuel);
        lc->size--;
        return 0;
    }
    /*
    if ((lc->head == NULL) || (persactuelle == lc->tail)) {
        if (persactuelle->identifiant == p1->identifiant) {
            Personne *p = lc->tail;
            lc->tail = (lc->tail)->precedent;
            free(p);
            lc->size--;
        }
        else {
            return 1;                          //La personne à supprimer n'existe pas.
        }
    }
    
    else {
        (persactuelle->precedent)->suivant = persactuelle->suivant;
        free(persactuelle);
        lc->size--;
    }
    
    return 0;*/
}
