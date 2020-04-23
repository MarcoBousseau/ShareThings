#include <pwd.h>
#include <unistd.h>
#include "fHashCode.h"

unsigned int HashCode (char  *ligne)
{
    unsigned int Code = 0;
    size_t const len = strlen (ligne);
    size_t i;
    
    //  printf ("ligne = '%s'\n", ligne);
    
    for (i = 0; i < len; i++)
    {
        Code = ligne[i] + 31 * Code;
    }
    return Code % 101;
}
