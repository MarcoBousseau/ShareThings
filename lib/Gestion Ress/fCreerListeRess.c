#include "fCreerListeRess.h"

TtesRessources creerTtesRess() {
    TtesRessources tr = (TtesRessources)malloc(sizeof(TtesRessources));
    tr->head = NULL;
    tr->tail = NULL;
    tr->size = 0;
    return tr;
}
