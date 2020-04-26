//
//  ShareThings.h
//  
//
//  Created by Marco Bousseau on 10/03/2020.
//

#ifndef ShareThings_h
#define ShareThings_h

#include <stdio.h>

typedef struct Date {
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Ressource {
    enum { LIVRE=0, PC=1, OUTILS=2, CAPTEURS=3, AUTRE=4 }type;
    int disponible;
    struct Personne *emprunteur;
    struct Personne *proprietaire;
}Ressource;

typedef struct Personne {
    char *Nom[30];
    char *Prenom[30];
    char *identifiant[30];
    char *mdp[15];
    struct Ressource *emprunts[30];
    struct Ressource *prets[30];
}Personne;

typedef struct s_clients {
    Personne *head;
    Personne *tail;
    int size;
} ListeClients;


typedef struct s_ttesRess {
    Personne *head;
    Personne *tail;
    int size;
} TtesRessources;
/*
typedef struct Ressource;

typedef struct Personne;

typedef struct Date;*/

int MenuAccueil();
unsigned int HashCode(char *);
int authentificationAdmin(char []);
int authentificationClient(char []);

int menuAdmin();

int ajouterPersonne(struct Personne p1);
int modifPersonne();
int supprPersonne();
int afficheListeClients();

int menuDemandeurPreteur();

struct Ressource rechercheParType();
int nbRessEmprPrete();
int nbRessPrete();
int ListeOperationsPeriod(struct Date /*debut*/, struct Date /*fin*/);
struct Date finDePret(struct Ressource r);
int retirerRessource();
int supprCoord();
int transfert();

#endif /* ShareThings_h */
