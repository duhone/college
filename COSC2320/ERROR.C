#include <stdio.h>
#include <stdlib.h>   /*for prototype of exit*/
#include "d:\cosc2320\error.h"

void FatalError(char msg[ ])
{  fprintf(stderr, "\nFATAL ERROR: %s\n", msg);
   exit(1);
}

void Error(char msg[ ])
{  fprintf(stderr, "\nERROR: %s\n", msg);
}
