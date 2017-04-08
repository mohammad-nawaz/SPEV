/* -----------------------------------------------------------------------------
 * DESCRIPTION: Set the background from pluto output file (.dbl file) and grid 
 * information. 
 * AUTHOR: M A Nawaz(ali.nawaz.md@gmail.com)
 * DATE: 13 March 2017
 * -------------------------------------------------------------------------- */
#include "spev.h"

/* -------------------------------------------------------------------------- */
void SetBackground (){
/* 
 * TASK:
 * PARAMETERS:
 *
 * RETURN:
 * -------------------------------------------------------------------------- */
    char fname[20] = "data.0040.dbl";
    FILE *fbin; 
    Bg_Input *bg_input;
    Bg_Input bin;
    bg_input = &bin;
    Bg_Data *bg_data;
    Bg_Data bd;
    bg_data = &bd;
    void *Vpt; 
    int nv;

    printf("set_background.c/SetBackground(): \n");

    /* Open background binary data file */
    fbin = OpenBinaryFile(fname, "r");


   /* Memory allocation for pointers*/
    bg_data->Vc = QPtr(NVAR, NX3_TOT, NX2_TOT, NX1_TOT, double);

    /* Set Array pointers of the actual background data coordinated with the 
     * Bg_Input structures */
    for (nv = 0; nv < NVAR; nv++){
      bg_input->V[nv]        = bg_data->Vc[nv];
    }

    /* Pointer for the acutal data */
    for (nv = 0; nv < bg_input->nvar; nv++) {
        Vpt = (void *)bg_input->V[nv][0][0];
    }

    printf("I am here!\n");

    /* Read Binary file for Data array */
    for (nv = 0; nv < bg_input->nvar ; nv++)
    {
	ReadBinaryFile(Vpt, sizeof(double), fbin);
    }

    /* Get PLUTO variable names */
    GetPlutoVarNames(bg_input);

}

/* -------------------------------------------------------------------------- */
void GetPlutoVarNames(Bg_Input *bg_input)
/* 
 * TASK: Provide variable names for the background data. Variable names are kept
 *     	 the same as in the PLUTO. 
 * PARAMETERS: 
 * 
 * RETURN: 
 * Ref: PLUTO/SetDefaultVarNames()
 * -------------------------------------------------------------------------- */
{
    printf("set_background.c/GetPlutoVarNames(): \n");

    bg_input->nvar = NVAR;
    printf("No. of variables: %d\n", bg_input->nvar);

    bg_input->var_name = DPtr(64, 128, char);
//    bg_input->var_name[0] = "rho";
    bg_input->var_name[RHO] = "rho";

    EXPAND(bg_input->var_name[VX1] = "vx1";  ,
	    bg_input->var_name[VX2] = "vx2";  ,
	    bg_input->var_name[VX3] = "vx3";)
    bg_input->var_name[PRS] = "prs";
    EXPAND(bg_input->var_name[BX1] = "bx1";  ,
            bg_input->var_name[BX2] = "bx2";  ,
            bg_input->var_name[BX3] = "bx3";)
    
}

