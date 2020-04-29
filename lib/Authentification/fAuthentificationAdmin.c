#include "Authentification/hAuthent.h"
#include "fHashCode.h"
#include <stdio.h>
#include "fAuthentificationAdmin.h"

int authentificationAdmin(char mdpAdmin[]){
    char entree[15];
    int i;
    for (i=0; i<15; i++) {
        entree[i] = '_';
    }
    char c;
    i=0;
    //while(i<15){
    printf("\t\tAuthentification\n\n\t\tmdp (en entrant à chaque caractère) : %s", entree);
    scanf("%s", /*&*/entree);
    //        entree[i] = c;
    i++;
    //}
    switch(HashCode(mdpAdmin) == HashCode(entree)){
        case 1:
            return 1;
        case 0:
            return 0;
        default:
            return 0;
    }
    
}
