#include "fCreerPers.h"
#include "ShareThings.h"

Personne creerPersonne(){
    p1 = (Personne *)malloc(sizeof(Personne));
    
    printf("Saisir le Nom (15 caracteres maximum):");
    scanf("%s",&(p1->Nom));
    
    printf("Saisir le Prenom (15 caracteres maximum):");
    scanf("%s",&(p1->Prenom));
    
    printf("Saisir l'Identifiant' (15 caracteres maximum):");
    scanf("%s",&(p1->identifiant));

    printf("Saisir le Mot de passe (15 caracteres maximum):");
    scanf("%s",&(p1->mdp));

    return p1;
}
