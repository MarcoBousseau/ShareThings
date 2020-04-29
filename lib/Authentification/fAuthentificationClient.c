#include "fAuthentificationClient.h"
#include "Authentification/hAuthent.h"
#include "fHashCode.h"
#include <stdio.h>

int authentificationClient(ListeClients mainLC){
    char entreeId[15];
    char entreeMdp[15];
    int res = 0;
    printf("\t\tAuthentification\n\n\t\tidentifiant :");
    res = scanf("%s", entreeId);
    int i;
    int compt = 0;
    Personne actuel = mainLC->head;         //lc correspond à la liste des clients.
    if (res == 1) {
        while ((actuel != NULL) && (compt != 30)) {
            for (i=0; i <= 29; i++) {
                if ((actuel->identifiant)[i] == entreeId[i]) {
                    compt++;
                }
            }
            if (compt != 30) {
                compt = 0;
                actuel = actuel->suivant;
            }
        }
        
        if (actuel == NULL) {
            printf("L'identifiant rentré ne correspond à aucun client.");
            return 0;
        }
        else {
            //traitement du mot de passe
            printf("mdp : ");
            scanf("%s", entreeMdp);
            switch(HashCode(actuel->mdp) == HashCode(entreeMdp)){
                case 1:
                    return 1;
                case 0:
                    printf("\t\tMot de passe invalide.");
                    return 0;
                default:
                    return 0;
            }
        }
    }
    else {
        printf("Vous avez fais une erreur lors de la saisie");
        return 0;
    }
}
