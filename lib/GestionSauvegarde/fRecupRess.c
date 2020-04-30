#include "fRecupRess.h"
#include "GestionSauvegarde/hGestSave.h"

int recupRessources(TtesRessources tr) {            //on recupere le fichier sauvegarde de l'ensemble des ressources.
    FILE* fichier = NULL;
    char chaine[35] = "";
    fichier = fopen("ressources.txt", "r");     //on ouvre le fichier en question.
    
    if (fichier == NULL) {              //on verifie si il a ete ouvert avec succes.
        printf("Impossible d'ouvrir le fichier ressourcess.txt");
        return 1;
    }
    
    else {
        Ressource pre = NULL;
        Ressource actuel = NULL;
        
        while ((fgets(chaine, 35, fichier) != NULL) // On continue tant que fgets n'a pas retourné NULL (fin de fichier)
               {
                   
                   if (pre != NULL) {                  //si l'on est pas sur la ressource "head" (precedent NULL), on passe a la ressource suivante.
                       actuel = actuel->suivant;
                   }
                   actuel->precedent = pre;           //la ressource precedant l'actuelle prend la valeur qu'on lui a donne.
                   
                   if (chaine == "0") {            //tests pour le type de la ressource.
                       actuel->type = 0;
                   }
                   else if (chaine == "1") {
                       actuel->type = 1;
                   }
                   else if (chaine == "2") {
                       actuel->type = 2;
                   }
                   else if (chaine == "3") {
                       actuel->type = 3;
                   }
                   else if (chaine == "4") {
                       actuel->type = 4;
                   }
                   
                   fgets(chaine, 35, fichier);     //tests pour la disponibilite de la ressource.
                   if (chaine == "0") {
                       actuel->disponible = 0;
                   }
                   else if (chaine == "1") {
                       actuel->disponible = 1;
                   }
                   
                   fgets(chaine, 35, fichier);         //on injecte dans la ressource actuelle tous ses parametres.
                   actuel->Nom = chaine;
                   
                   fgets(chaine, 35, fichier);
                   actuel->idemprunteur = chaine;
                   
                   fgets(chaine, 35, fichier);
                   actuel->idproprietaire = chaine;
                   
                   fgets(chaine, 35, fichier);
                   if (chaine == "n") {            //on teste si la ressource a une date de debut d'emprunt ou non.
                       actuel->debut = NULL;
                   }
                   else {
                       char *j = chaine;                   //on "convertit" la chaine en un entier pour chaque composante de la date.
                       (actuel->debut)->jour = atoi(j);
                       
                       fgets(chaine, 10, fichier);
                       char *m = chaine;
                       (actuel->debut)->mois = atoi(m);
                       
                       fgets(chaine, 10, fichier);
                       char *a = chaine;
                       (actuel->debut)->annee = atoi(a);
                   }
                   
                   
                   if (pre == NULL) {             //si l'on est sur la ressource "head", alors on la definit comme tel dans la liste des ressources.
                       lc->head = actuel;
                   }
                   if (pre =! NULL) {              //si l'on est pas sur la resource "head", alors la ressource precedente pointe vers l'actuelle.
                       pre->suivant = actuel;
                   }
                   pre = actuel;                   //on change la valeur de la ressource precedente.
               }
               
               lc->tail = actuel;          //lorsque la boucle est terminee on a alors atteint la fin du fichier et donc de la liste des ressources, la derniere ressource devient donc la "tail" de la liste.
               fclose(fichier);            //on ferme le fichier.
               
               }
               return 0;
               }
