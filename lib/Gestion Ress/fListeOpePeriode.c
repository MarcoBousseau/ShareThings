#include "ShareThings.h"
#include "fListeOpePeriode.h"

int ListeOperationsPeriod(Date deb, Date fin, Personne *p1) {
    printf("\t Prêts effectués sur la période choisie : \n");
    int i=0;
    int j=0;
    Date datedeb;
    Ressource *pret = p1->prets;
    Ressource *empr = p1->emprunts;
    Ressource *res = pret[i];
    while ((res != NULL) && (i < 30)) {
        datedeb = res->debut;
        if ((datedeb.annee <= fin.annee) && (datedeb.annee >= deb.annee)) {
            if ((datedeb.mois <= fin.mois) && (datedeb.mois >= deb.mois)) {
                if ((datedeb.jour <= fin.jour) && (datedeb.jour >= deb.jour)) {
                    printf("%s\n", res->Nom);
                }
            }
        }
        i++;
        res = pret[i];
    }
    
    printf("\t Emprunts effectués sur la période choisie : \n");
    res = empr[j];
    while ((res != NULL) && (j < 30)) {
        datedeb = res->debut;
        if ((datedeb.annee <= fin.annee) && (datedeb.annee >= deb.annee)) {
            if ((datedeb.mois <= fin.mois) && (datedeb.mois >= deb.mois)) {
                if ((datedeb.jour <= fin.jour) && (datedeb.jour >= deb.jour)) {
                    printf("%s\n", res->Nom);
                }
            }
        }
        j++;
        res = empr[j];
    }
    
    return 0;
}
