#include "fSupprRess.h"
#include "ShareThings.h"
#include "fRetirerRess.h"

int retirerRessource(TtesRessources tr, Ressource *r, Personne *pers){        //pers désigne la personne connectée
    Personne proprio = r->proprietaire;
    if (r->disponible == 1) && (proprio->identifiant == pers->identifiant) {
        supprRessempr(tr, r);
    }
}
