#include "fRetirerRess.h"
#include "GestionRess/hGestRess.h"

int supprRessempr(TtesRessources tr, Ressource *res) {         //supprimer une ressource de la liste des ressources quand le propriétaire la retire
    Ressource *resactuelle = tr->head;
    while (((resactuelle->Nom != res->Nom) || (resactuelle->type != res->type)) && ((resactuelle != tr->tail))) {
        resactuelle = resactuelle->suivant;
    }
    
    if ((tr->head == NULL) || (resactuelle == tr->tail)) {
        if ((resactuelle->Nom == res->Nom) && (resactuelle->type == res->type)) {
            Ressource *r = tr->tail;
            tr->tail = (tr->tail)->precedent;
            free(r);
            tr->size--;
            return 0;
        }
        else {
            return 1;                                               //La ressource à supprimer n'existe pas.
        }
    }
    
    else {
        (resactuelle->precedent)->suivant = resactuelle->suivant;
        free(resactuelle);
        tr->size--;
    }
    
    return 0;
}

