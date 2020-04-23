#include "fNbRessEmpre.h"
#include "ShareThings.h"

int nbRessEmpr(Personne *p1) {           //désigne la personne connectée
    int i=0;
    int compt=0;
    struct Ressource empr = p1->emprunts;
    while (empr[i] != NULL) {
        compt++;
        i++;
    }
    return compt;
}
