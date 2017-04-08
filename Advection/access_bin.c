/* -----------------------------------------------------------------------------
 * DESCRIPTION: Access binary files
 * AUTHOR: M A Nawaz(ali.nawaz.md@gmail.com)
 *
 * DATE: 12 March 2017
 * -------------------------------------------------------------------------- */
#include "spev.h"

/* -------------------------------------------------------------------------- */
FILE *OpenBinaryFile (char *filename, char *mode)
/*!
 * TASK: Open a binary file in read or write mode. 
 * PARAMETERS:
 *	filename [in]: A file name. 
 * 	mode     [in]: mode "r" for reading file, and "w" for writing
 *
 * RETURN: The pointer to the file.
 *  ------------------------------------------------------------------------- */
{
    FILE *fp;

    printf("acces_bin.c/OpenBinaryFile(): \n");
    if (strcmp(mode, "r")==0){
	fp = fopen(filename, "rb");
	/* Check whether the file exists */
	if (!fp){
	    printf("There is no such file called %s\n", filename);
	    QUIT_SPEV(1);
	}
    }

    return(fp);
}

/* -------------------------------------------------------------------------- */
void ReadBinaryFile (void *Vpt, size_t dsize, FILE *fbin)
/* 
 * TASK: 
 * PARAMETERS:
 *
 * RETURN: 
 * -------------------------------------------------------------------------- */
{
    char *Vc; 

    int i, j, k;

    Vc = (char *) Vpt;



    for (k = KBEG; k <= KEND ; k++)
    {
        for (j = JBEG; j <= JEND; j++) 
        {   
            i = IBEG + (NX1_TOT )*(j + NX2_TOT*k);
            fread (Vc + i*dsize, dsize, NX1 , fbin);
        }
    }
}
