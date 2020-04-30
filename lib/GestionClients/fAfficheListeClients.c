#include "GestionClients/hGestCli.h"
#include "GestionClients/fAfficheListeClients.h"

int afficheListeClients(ListeClients lc) {
    Personne * clientactuel = lc->head;
    char n;
    char p;
    if (lc->head == NULL) {
        return 1;                           //Aucun client à afficher.
    }
    else {
        while (clientactuel != NULL) {
            p = clientactuel->Prenom;
            n = clientactuel->Nom;
            printf("%s\t %s\n", p, n);
            clientactuel = clientactuel->suivant;
        }
    }
    return 0;
}
