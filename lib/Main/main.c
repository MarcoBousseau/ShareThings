#include "ShareThings.h"

struct _date {
    int jour;
    int mois;
    int annee;
};

struct _ressource {
    typedef enum { LIVRE=0, PC=1, OUTILS=2, CAPTEURS=3, AUTRE=4 }type;
    int disponible;
    char Nom[30];
    char idemprunteur[30];
    char idproprietaire[30];
    Date debut;
    Ressource precedent;
    Ressource suivant;
};

struct _personne {
    char Nom[30];
    char Prenom[30];
    char identifiant[30];
    char mdp[30];
    Resource emprunts[30];
    Ressource prets[30];
    Personne precedent;
    Personne suivant;
};

struct s_clients {
    Personne *head;
    Personne *tail;
    int size;
};

 struct s_ttesRess {
    Personne *head;
    Personne *tail;
    int size;
};


int main(){
    // RECUPERATION DES DONNEES
    ListeClients mainLC;
    mainLC = creerListe();
    recupClients(mainLC);
    
    TtesRessources mainLR;
    mainLR = creerTtesRess();
    recupRessources(mainLR);
    
    // ACCES AUX MENUS ET DEPLACEMENT EN LEUR SEIN
    int menu = 0;
    while(menu != 3){
        menu = menuAccueil();
        switch (menu) {
            case 1:
                int test = 0;
                while(! test){
                    test = authentificationAdmin(mdpAdmin);
                }
                int saisieAdmin;
                saisieAdmin = 0;
                while(saisieAdmin!=5){
                    saisieAdmin = menuAdmin();
                    switch (saisieAdmin) {
                        case 1:
                            Personne PersAjout;
                            PersAjout = creerPersonne();
                            ajouterPersonne(mainLC, PersAjout);
                            break;
                        case 2:
                            char id[30];
                            int i;
                            int compt = 0;
                            int res = 0;
                            Personne actuel = mainLC->head;         //lc correspond à la liste des clients.
                            printf("Entrez l'identifiant de la personne que vous souhaitez modifier :\n");
                            res = scanf("%s", id);
                            if (res == 1) {
                                while ((actuel != NULL) && (compt != 30)) {
                                    for (i=0; i <= 29; i++) {
                                        if ((actuel->identifiant)[i] == id[i]) {
                                            compt++;
                                        }
                                    }
                                    if (compt != 30) {
                                        compt = 0;
                                        actuel = actuel->suivant;
                                    }
                                }
                                
                                if (actuel == NULL) {
                                    printf("L'identifiant rentré ne correspond à aucun client.")
                                }
                                else {
                                    modifierPersonne(actuel);
                                }
                            }
                            else {
                                printf("Vous avez fais une erreur lors de la saisie");
                            }
                            break;
                        case 3:
                            Personne persASupp;
                            int i;
                            int compt = 0;
                            int res = 0;
                            printf("Entrez l'identifiant de la personne que vous souhaitez supprimer :\n");
                            res = scanf("%s", (persASupp->identifiant));
                            if (res == 1) {
                                supprPersonne(mainLC, actuel);
                            }
                            else {
                                printf("Vous avez fais une erreur lors de la saisie");
                            }
                            break;
                        case 4:
                            afficheListeClients(mainLC);
                            break;
                        default:
                            break;
                    }
                }
                //retour accueil
                break;
            case 2:
                int test = 1;
                while(test){
                    test = authentificationClient();
                }
                int saisieClient;
                saisieClient = menuClient();
                while(saisieClient!=4){
                    switch (saisieClient) {
                        case 1:
                            //rech par type
                            int typeRech;
                            printf("\t\tChoisir le Type de Ressource recherché :\n\t\t0 pour un Livre,\n\t\t1 pour un PC portable,\n\t\t2 pour un outils,\n\t\t3 pour un Capteur,\n\t\t4 pour autre chose.")
                            scanf("%d", &typeRech);
                            rechercheParType(mainLR, typeRech);
                            break;
                        case 2:
                            //menu gerer mes ress
                            int saisieGestRess;
                            saisieGestRess = menuGestionRess();
                            while(saisieGestRess!=6){
                                switch (saisieGestRess) {
                                    case 1:
                                        //Nb Ressources Pretees
                                    case 2:
                                        //Nb de Ressources empruntees
                                        break;
                                    case 3:
                                        //Fin de pret
                                        break;
                                    case 4:
                                        //Liste Operations periode
                                    case 5:
                                        //Supprimer une de mes ressources
                                    default:
                                        break;
                                }
                                saisieGestRess = menuGestionRess();
                            }
                            //retour menuClient()
                            break;
                        case 3:
                            //gerer mes info perso
                            int saisieGestInfos;
                            saisieGestInfos = menuGestionInfos();
                            while(saisieGestInfos!=6){
                                switch (saisieGestInfos) {
                                    case 1:
                                        //Changer mdp (Modifier personne de moi)
                                    case 2:
                                        //Changer coordonnees (Modifier personne de moi)
                                        break;
                                    case 3:
                                        //Fin de pret
                                        break;
                                    case 4:
                                        //Liste Operations periode
                                    case 5:
                                        //Supprimer mon compte
                                    default:
                                        break;
                                }
                                saisieGestInfos = menuGestionInfos();
                            }
                            //retour menuClient()
                            break;
                        default:
                            break;
                    }
                    saisieClient = menuClient();
                }
                //retour accueil
                break;
            case 3:
                saveClients(mainLC);
                saveRessources(mainLR);
                printf("Merci d'avoir utilisé ShareThings, et a bientot !");
                return 0;
            default:
                break;
        }
    }
    return 0;
}




