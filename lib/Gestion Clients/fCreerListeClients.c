#include "fCreerListeClients.h"

ListeClients creerListe() {
    ListeClients lc = (ListeClients)malloc(sizeof(ListeClients));
    lc->head = NULL;
    lc->tail = NULL;
    lc->size = 0;
    return lc;
}
