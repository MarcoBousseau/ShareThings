#include "fSaveClient.h"
#include "ShareThings.h"

int saveClients(ListeClients lc) {              //sauvegarde les clients dans un fichier
    
    FILE* fichier = NULL;
    
    fichier = fopen("clients.txt", "w");        //on ouvre le fichier dans lequel on va ecrire.
    
    if (fichier == NULL) {                      //on test si le fichier s'est bien ouvert.
        printf("Impossible d'ouvrir le fichier clients.txt");
        return 1;
    }
    
    else {
        Personne* clientactuel = lc->head;
        
        while (clientactuel != NULL) {                      //la boucle permet de sauvegarder la liste des clients.
            fprintf(fichier, "%s\n", clientactuel->Nom);        //on ecrit dans le fichier ligne par ligne chaque personne et ses infos.
            fprintf(fichier, "%s\n", clientactuel->Prenom);
            fprintf(fichier, "%s\n", clientactuel->identifiant);
            fprintf(fichier, "%s\n", clientactuel->mdp);
            
            int i=0;
            int j=0;
            Ressource* empr = clientactuel->emprunts;
            Ressource* pret = clientactuel->prets;
            while (i <= 29) {                       //cette boucle sert a ecrire toutes les ressources empruntees de la personne acutelle dont on sauvegarde les donnees.
                
                Date edate = (empr[i])->debut;
                if (empr[i] == NULL) {
                    fputs("r ", fichier);
                }
                
                else {
                    fprintf(fichier, "%d %d\n", (empr[i])->type, (empr[i])->disponible);
                    fprintf(fichier, "%s\n", (empr[i])->Nom);
                    fprintf(fichier, "%s\n", (empr[i])->idemprunteur);
                    fprintf(fichier, "%s\n", (empr[i])->idproprietaire);
                    
                    if (edate != NULL) {        //si la ressource a deja ete empruntee == si il y a une date de debut.
                        fprintf(fichier, "%d\n", edate->jour);
                        fprintf(fichier, "%d\n", edate->mois);
                        fprintf(fichier, "%d\n", edate->annee);
                    }
                    else {
                        fputs("n\n", fichier);
                    }
                }
                
                i++;
            }
            
            while (j <= 29) {                   //meme chose pour cette boucle mais avec les ressources pretees.
                
                Date pdate = (pret[j])->debut;
                if (pret[j] == NULL) {
                    fputs("r\n", fichier);
                }
                
                else {
                    fprintf(fichier, "%d\n", (pret[j])->type);
                    fprintf(fichier, "%d\n", (pret[j])->disponible)
                    fprintf(fichier, "%s\n", (pret[j])->Nom);
                    fprintf(fichier, "%s\n", (pret[j])->idemprunteur);
                    fprintf(fichier, "%s\n", (pret[j])->idproprietaire);
                    
                    if (pdate != NULL) {        //si la ressource a deja ete empruntee == si il y a une date de debut.
                        fprintf(fichier, "%d\n", pdate->jour);
                        fprintf(fichier, "%d\n", pdate->mois);
                        fprintf(fichier, "%d\n", pdate->annee);
                    }
                    else {
                        fputs("n\n", fichier);
                    }
                }
                
                j++;
            }
            
            clientactuel = clientactuel->suivant;       //permet de passer au client suivant pour pouvoir bien ecrire dans le fichier tous les clients
        }
        
        fclose(fichier);            //on ferme le fichier une fois que l'on a fini.
    }
    
    return 0;
}
