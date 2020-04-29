#include "fFinDePret.h"
#include "GestionRess/hGestRess.h"

int finDePret(Ressource *r) {
    r->disponible = 1;
    
    int i=0;
    Ressource *res;
    res = (r->emprunteur)->emprunts;
    Ressource *asupr = res[i]
    while (((asupr->Nom != r->Nom) || (asupr->type != r->type)) && (i < 30)) {
        i++;
        if (i <= 30 - 1) {
            asupr = res[i];
        }
    }
    if (res[0] == NULL) || (i == 30) {
        return 1;                                   //La personne à supprimer n'existe pas.
    }
    
    else {
        int j;                                //j représente la position dans le le tableau des emprunts de la ressource à supprimer.
        for (j=i; j < 30 - 1; j++) {
            ((r->emprunteur)->emprunts)[j] = ((r->emprunteur)->emprunts)[j+1];
        }
    }
    return 0;
    
    r->emprunteur = NULL;
}
