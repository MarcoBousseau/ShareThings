#include "fCreerListeClients.h"

void creerListe() {
    ListeClients lc = (ListeClients)malloc(sizeof(ListeClients));
    lc->head = NULL;
    lc->tail = NULL;
    lc->size = 0;
}
