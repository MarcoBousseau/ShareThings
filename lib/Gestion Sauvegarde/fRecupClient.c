#include "fRecupClient.h"
#include "ShareThings.h"

int recupClients(ListeClients lc) {             //recupere les clients du fichier sauvegarde.
    FILE* fichier = NULL;
    
    fichier = fopen("clients.txt", "r");        //on ouvre le fichier en question.
    
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier clients.txt");       //on verifie si il a ete ouvert avec succes.
        return 1;
    }
    
    else {
        Personne pre = NULL;
        Personne actuel = NULL;
        while ((fgets(chaine, 35, fichier) != NULL) // On continue tant que fgets n'a pas retourné NULL (fin de fichier)
               {
                   
                   if (pre != NULL) {
                       actuel = actuel->suivant;            //si l'on est pas sur la personne "head" (precedent NULL), on passe a la personne d'apres.
                   }
                   actuel->precedent = pre;                //la personne precedant l'actuelle dans la liste prend la valeur qu'on lui a donne.
                   
                   // On lit la chaine de caractères
                   actuel->Nom = chaine;                   //on recupere chaque info de chaque client;
                   fgets(chaine, 35, fichier);
                   actuel->Prenom = chaine;
                   fgets(chaine, 35, fichier);
                   actuel->identifiant = chaine;
                   fgets(chaine, 35, fichier);
                   actuel->mdp = chaine;
                   
                   int i = 0;
                   int j = 0;
                   Ressource empr[30];
                   Ressource pret[30];
                   while (i <= 29) {                       //on recupere la liste des ressources empruntees.
                       
                       fgets(chaine, 35, fichier);
                       if (chaine == "r") {
                           empr[i] = NULL;
                       }
                       else {
                           if (chaine == "0") {            //test pour le type.
                               (empr[i])->type = 0;
                           }
                           else if (chaine == "1") {
                               (empr[i])->type = 1;
                           }
                           else if (chaine == "2") {
                               (empr[i])->type = 2;
                           }
                           else if (chaine == "3") {
                               (empr[i])->type = 3;
                           }
                           else if (chaine == "4") {
                               (empr[i])->type = 4;
                           }
                           
                           fgets(chaine, 35, fichier);
                           if (chaine == "0") {                    //test pour si ressource disponible ou non.
                               (empr[i])->disponible = 0;
                           }
                           else if (chaine == "1") {
                               (empr[i])->disponible = 1;
                           }
                           
                           fgets(chaine, 35, fichier);
                           (empr[i])->Nom = chaine;
                           
                           fgets(chaine, 35, fichier);
                           (empr[i])->idemprunteur = chaine;
                           
                           fgets(chaine, 35, fichier);
                           (empr[i])->idproprietaire = chaine;
                           
                           fgets(chaine, 10, fichier);
                           if (chaine == "n") {            //on teste si la ressource a une date de debut d'emprunt ou non.
                               (empr[i])->debut = NULL;
                           }
                           
                           else {
                               char *j = chaine;                           //permet de "convertir" la chaine en int pour chaque donnee de la date.
                               ((empr[i])->debut)->jour = atoi(j);
                               
                               fgets(chaine, 10, fichier);
                               char *m = chaine;
                               ((empr[i])->debut)->mois = atoi(m);
                               
                               fgets(chaine, 10, fichier);
                               char *a = chaine;
                               ((empr[i])->debut)->annee = atoi(a);
                           }
                           
                           (empr[i])->suivant = NULL;
                           (empr[i])->precedent = NULL;
                           
                       }
                       i++;
                   }
                   
                   actuel->emprunts = empr;            //une fois la liste des emprunts completee on la remet a la personne concernee.
                   
                   while (j <= 29) {                   //on recupere la liste des ressources pretees.
                       fgets(chaine, 35, fichier);
                       if (chaine == "r") {
                           pret[j] = NULL;
                       }
                       else {
                           if (chaine == "0") {
                               (pret[j])->type = 0;
                           }
                           else if (chaine == "1") {
                               (pret[j])->type = 1;
                           }
                           else if (chaine == "2") {
                               (pret[j])->type = 2;
                           }
                           else if (chaine == "3") {
                               (pret[j])->type = 3;
                           }
                           else if (chaine == "4") {
                               (pret[j])->type = 4;
                           }
                           
                           fgets(chaine, 35, fichier);
                           if (chaine == "0") {
                               (pret[j])->disponible = 0;
                           }
                           else if (chaine == "1") {
                               (pret[j])->disponible = 1;
                           }
                           
                           fgets(chaine, 35, fichier);
                           (pret[j])->Nom = chaine;
                           
                           fgets(chaine, 35, fichier);
                           (pret[j])->idemprunteur = chaine;
                           
                           fgets(chaine, 35, fichier);
                           (pret[j])->idproprietaire = chaine;
                           
                           fgets(chaine, 10, fichier);
                           if (chaine == "n") {            //on teste si la ressource a une date de debut d'emprunt ou non.
                               (pret[j])->debut = NULL;
                           }
                           
                           else {
                               char *j = chaine;                       //permet de "convertir" la chaine en int pour chaque donnee de la date.
                               ((pret[j])->debut)->jour = atoi(j);
                               
                               fgets(chaine, 10, fichier);
                               char *m = chaine;
                               ((pret[j])->debut)->mois = atoi(m);
                               
                               fgets(chaine, 10, fichier);
                               char *a = chaine;
                               ((pret[j])->debut)->annee = atoi(a);
                           }
                           
                           (pret[j])->suivant = NULL;
                           (pret[j])->precedent = NULL;
                       }
                       j++;
                   }
                   
                   actuel->prets = pret;       //une fois la liste des emprunts completee on la remet a la personne concernee.
                   
                   if (pre == NULL) {          //si l'on est sur la personne "head" (precedent NULL), alors on la definie comme tel dans la liste des clients.
                       lc->head = actuel;
                   }
                   if (pre =! NULL) {          //si l'on est pas sur la personne "head", le suivant de son precedent pointe donc vers la personne actuelle.
                       pre->suivant = actuel;
                   }
                   pre = actuel;
                   
               }
               lc->tail = actuel;          //une fois la boucle achevee, on est à la fin du fichier donc des clients, la personne "tail", est donc celle qu'il nous reste.
               fclose(fichier);            //on ferme le fichier.
               }
               return 0;
               }

