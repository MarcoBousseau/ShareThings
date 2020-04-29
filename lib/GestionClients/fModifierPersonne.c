#include "fModifierPersonne.h"
#include "GestionClients/hGestCli.h"


int modifierPersonne(Personne p1) {
    int choix = 0;
    char modif[30];
    printf("Entrez le numéro selon ce que vous souhaitez modifier : \n");
    printf("\t1 : modifier le Nom.\n");
    printf("\t2 : modifier le Prenom.\n");
    printf("\t3 : modifier l'identifiant\n");
    printf("\t4 : modifier le mot de passe.\n");
    
    scanf("%d", choix);
    
    if (choix == 1) {
        printf("Entrez le nouveau Nom :\n");
        scanf("%s", modif);
        actuel->Nom = modif;
    }
    
    if (choix == 2) {
        printf("Entrez le nouveau Prenom :\n");
        scanf("%s", modif);
        actuel->Prenom = modif;
    }
    
    if (choix == 3) {
        printf("Entrez le nouvel identifiant :\n");
        scanf("%s", modif);
        actuel->identifiant = modif;
    }
    
    if (choix == 4) {
        printf("Entrez le nouveau mot de passe :\n");
        scanf("%s", modif);
        actuel->mdp = modif;
    }
    
    return 0;
}
