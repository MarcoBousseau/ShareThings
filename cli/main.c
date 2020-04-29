#include "Main/ShareThings.h"
#include "Authentification/fAuthentificationAdmin.h"
#include "Authentification/fAuthentificationClient.h"
#include "Authentification/fHashCode.h"
#include "GestionClients/fAfficheListeClients.h"
#include "GestionClients/fAjouterPersonne.h"
#include "GestionClients/fCreerListeClients.h"
#include "GestionClients/fCreerPers.h"
#include "GestionClients/fModifierPersonne.h"
#include "GestionClients/fSupprPers.h"
#include "GestionRess/fCreerListeRess.h"
#include "GestionRess/fEmprunterRess.h"
#include "GestionRess/fFinDePret.h"
#include "GestionRess/fListeOpePeriode.h"
#include "GestionRess/fNbRessEmpr.h"
#include "GestionRess/fNbRessEmprPretee.h"
#include "GestionRess/fNbRessPretee.h"
#include "GestionRess/fRechParType.h"
#include "GestionRess/fRetirerRess.h"
#include "GestionRess/fSupprPers.h"
#include "GestionRess/fSupprRess.h"
#include "GestionSauvegarde/fRecupClient.h"
#include "GestionSauvegarde/fRecupRess.h"
#include "GestionSauvegarde/fSaveClient.h"
#include "GestionSauvegarde/fSaveRess.h"
#include "Menus/fAccueil.h"
#include "Menus/fMenuAdmin.h"
#include "Menus/fMenuClients.h"
#include "Menus/fMenuGestionInfos.h"
#include "Menus/fMenuGestionRess.h"



struct _date {
    int jour;
    int mois;
    int annee;
};

struct _ressource {
    /*typedef*/enum { LIVRE=0, PC=1, OUTILS=2, CAPTEURS=3, AUTRE=4 }type;
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
    Ressource emprunts[30];
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
    char mdpAdmin[30];
    ListeClients mainLC;
    mainLC = creerListe();
    recupClients(mainLC, mdpAdmin);
    
    TtesRessources mainLR;
    mainLR = creerTtesRess();
    recupRessources(mainLR);
    
    // ACCES AUX MENUS ET DEPLACEMENT EN LEUR SEIN
    int menu = 0;
    int test, saisieAdmin, saisieClient, saisieGestRess, saisieGestInfos, typeRech;
    char id[30];
    Personne persASupp, PersAjout;
    while(menu != 3){
        menu = menuAccueil();
        switch (menu) {
            case 1:
                test = 0;
                while(! test){
                    test = authentificationAdmin(mdpAdmin);
                }
                saisieAdmin = 0;
                int i, compt, res;
                while(saisieAdmin!=5){
                    saisieAdmin = menuAdmin();
                    switch (saisieAdmin) {
                        case 1:
                            PersAjout = creerPersonne();
                            ajouterPersonne(mainLC, &PersAjout);
                            break;
                        case 2:
                            compt = 0;
                            res = 0;
                            Personne actuel = *(mainLC->head);         //lc correspond à la liste des clients.
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
                                    printf("L'identifiant rentré ne correspond à aucun client.");
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
                            //Personne persASupp;
                            compt = 0;
                            res = 0;
                            printf("Entrez l'identifiant de la personne que vous souhaitez supprimer :\n");
                            res = scanf("%s", (persASupp->identifiant));
                            if (res == 1) {
                                supprPersonne(mainLC, &actuel);
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
                test = 1;
                while(test){
                    test = authentificationClient(mainLC);
                }
                saisieClient = menuClients();
                while(saisieClient!=4){
                    switch (saisieClient) {
                        case 1:
                            //rech par type
                            printf("\t\tChoisir le Type de Ressource recherché :\n\t\t0 pour un Livre,\n\t\t1 pour un PC portable,\n\t\t2 pour un outils,\n\t\t3 pour un Capteur,\n\t\t4 pour autre chose.");
                            scanf("%d", &typeRech);
                            rechercheParType(mainLR, typeRech);
                            break;
                        case 2:
                            //menu gerer mes ress
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
                    saisieClient = menuClients();
                }
                //retour accueil
                break;
            case 3:
                saveClients(mainLC, mdpAdmin);
                saveRessources(mainLR);
                printf("Merci d'avoir utilisé ShareThings, et a bientot !");
                return 0;
            default:
                break;
        }
    }
    return 0;
}




