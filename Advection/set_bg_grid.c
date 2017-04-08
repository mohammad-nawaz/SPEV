/* -----------------------------------------------------------------------------
 * Description: Get the background grid from PLUTO simulation. 
 *
 * Author: M A Nawaz (ali.nawaz.md@gmai.com) 
 * Date: 26 March 2017
 * -------------------------------------------------------------------------- */
#include "spev.h"

//void SetGrid(Bg_Grid *grid)
void SetGrid()
{
    double xbeg; 
    char *s;
    char fname[20];
    char  *grid_label[] = {"X1-grid", "X2-grid","X3-grid"};
    int idim; 

    printf("set_bg_grid.c: SetGrid()\n");

    sprintf(fname, "pluto.ini");


    FileLines(fname);

    /* Get grid information from pluto.ini */

    FileParamVals(grid_label[0], 2);
}

