#include "fNbRessPretee.h"
#include "GestionRess/hGestRess.h"

int nbRessPrete(Personne *p1) {           //désigne la personne connectée
    int i=0;
    int compt=0;
    struct Ressource prete = p1->prets;
    while (prete[i] != NULL) {
        compt++;
        i++;
    }
    return compt;
}
