#include "fNbRessEmprPretee.h"
#include "ShareThings.h"

int nbRessEmprPrete(Personne p1){    //désigne le nombre total de ressources empruntées ou prêtées par la personne connectée
    
    int emp = nbRessEmpr(p1);
    int pre = nbRessPrete(p1);
    return (emp + pre);
}
