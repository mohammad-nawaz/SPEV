/* ----------------------------------------------------------------------------    
 * DESCRIPTION: Dynamically allocate memories for pointers in the heap.
 *
 * AUTHOR: M A Nawaz (ali.nawaz.md@gmail.com)
 * DATE: 19 March 2017
 * ------------------------------------------------------------------------- */
#include "spev.h"

/* ------------------------------------------------------------------------- */
char *SinglePtr (int nx, size_t dsize)
/* 
 * TASK: Allocate memory for a 2D array. 
 * PARAMETERS:
 *
 * RETURN:
 * ------------------------------------------------------------------------- */
{
    char *p;

    p    = (char *)malloc (nx * dsize);
    
    return p;
}


/* ------------------------------------------------------------------------- */
char **DoublePtr (int nx,int ny, size_t dsize)
/* 
 * TASK: Allocate memory for a 2D array.
 * PARAMETERS:
 *
 * RETURN:
 * ------------------------------------------------------------------------- */
{
    char **p;
    int i;

    p    = (char **)malloc ((size_t) nx * sizeof(char *));
    p[0] = (char *) malloc((size_t) nx * ny * sizeof(char));

    for (i = 1; i<nx; i++)
	p[i] = p[(i-1)] + ny*dsize;
    
    return p;
}

/* ------------------------------------------------------------------------- */
char ****QuadruplePtr (int nx,int ny, int nz, int nv, size_t dsize)
/* 
 * TASK: Allocate memory for a 4D array.
 * PARAMETERS:
 *
 * RETURN:
 * ------------------------------------------------------------------------- */
{
    char ****p;
    int i, j, k;

    /* Address Cascading */
    p    = (char ****)malloc ((size_t) nx * sizeof(char ***));
    p[0] = (char ***) malloc ((size_t) nx* ny * sizeof(char **));
    p[0][0] = (char **) malloc ((size_t) nx* ny * nz *sizeof(char *));
    p[0][0][0] = (char *) malloc ((size_t) nx* ny * nz * nv * sizeof(char));

    /* Contiguous memory for the array of triple pointers */
    for (i = 1; i<nx; i++)
	p[i] = p[(i-1)] + ny;

    /* Contiguous memory for the array of double pointers */
    /* 0s in the i direction */
    for (j = 1; j<ny; j++)
	p[0][j] = p[0][(j-1)] + nz;
    /* 0s in the j direction */
    for (i = 1; i<nx; i++)
	p[i][0] = p[(i-1)][0] + ny*nz;
    /* Other double pointers */
    for (i = 1; i<nx; i++)
    {
	for (j = 1; j<ny; j++)
	{
	    p[i][j] = p[i][(j-1)] + nz;
	}
    }

    /* Contiguous memory for the array of single pointers or, contiguous memory
     * for the addresses of the elements of 4D array.  */
    /* 0s in the i&j direction */
    for (k = 1; k < nz; k++)
	p[0][0][k] = p[0][0][(k-1)] + nv*dsize;
    /* 0s in the j&k direction */
    for (i = 1; i<nx; i++)
	p[i][0][0] = p[(i-1)][0][0] + ny * nz * nv * dsize; 
    /* 0s in the i&k direction */
    for (j = 1; j<ny; j++)
	p[0][j][0] = p[0][(j-1)][0] + nz * nv*dsize; 

    /* 0s in the i direction */
    for (j = 1; j<ny; j++)
    {
	for (k = 1; k<nz; k++)
	{
	    p[0][j][k] = p[0][j][(k-1)] + nv * dsize; 
	}
    }
    /* 0s in the j direction */
    for (i = 1; i<nx; i++)
    {
	for (k = 1; k<nz; k++)
	{
	    p[i][0][k] = p[i][0][(k-1)] + nv*dsize;
	}
    }
    /* 0s in the k direction */
    for (i = 1; i<nx; i++)
    {
	for (j = 1; j<ny; j++)
	{
	    p[i][j][0] = p[i][(j-1)][0] + nz*nv*dsize;
	}
    }
    /* Other single pointers */
    for (i = 1; i<nx; i++)
    {
	for (j = 1; j<ny; j++)
	{
	    for (k = 1; k<nz; k++)
	    {
		p[i][j][k] = p[i][j][(k-1)] + nv * dsize; 
	    }
	}
    }

    return p;

}
