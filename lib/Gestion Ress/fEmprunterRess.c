#include "fEmprunterRess.h"
#include "ShareThings.h"

int emprunterRess(Personne p1, Ressource res) {
    int i=0;
    
    if (res->disponible == 0) {             //on verifie si la ressource n'est pas deja empruntee.
        printf("La ressource demandée n'est pas disponible.\n");
        return 1;
    }
    else {
        while (((p1->emprunts)[i] != NULL) && (i < 30)) {       //on verifie si le tableau d'emprunts de la personne n'est pas complet, et sinon ou ajouter la ressource souhaitee.
            i++;
        }
        
        if (i == 30) {          //si la personne a deja le nombre maximum d'emprunts simultanes.
            printf("Vous avez atteint le nombre maximum d'emprunts.\n");
            return 1;
        }
        
        else {                  //si l'emprunt est possible.
            int j,m,a = 0;
            int result = 0;
            res->disponible = 0;            //on definit donc la ressource comme plus disponible.
            
            printf("Entrez le jour du début d'emprunt :\n");        //on donne a la rssource la date complete du debut de l'emprunt.
            result = scanf("%d", &j);
            if (result > 31) {
                printf("Le jour saisi n'est pas valable, resaisissez :\n");
                printf("Entrez le jour du début d'emprunt :\n");
                result = scanf("%d", &j);
            }
            (res->debut)->jour = result;
            
            printf("Entrez le mois du début d'emprunt :\n");
            result = scanf("%d", &m);
            if (result > 12) {
                printf("Le mois saisi n'est pas valable, resaisissez :\n");
                printf("Entrez le mois du début d'emprunt :\n");
                result = scanf("%d", &m);
            }
            (res->debut)->mois = result;
            
            printf("Entrez l'année du début d'emprunt :\n");
            result = scanf("%d", &a);
            if (result < 2020) {
                printf("L'année saisie n'est pas valable, resaisissez :\n");
                printf("Entrez l'année du début d'emprunt :\n");
                result = scanf("%d", &a);
            }
            (res->debut)->annee = result;
            
            (p1->emprunts)[i] = res;            //enfin on ajoute la ressource aux emprunts de la personne connectee.
        }
    }
}
