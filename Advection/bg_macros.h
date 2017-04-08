/* ----------------------------------------------------------------------------
 * Description: File generated during the runtime of pluto. This file contains 
 * macros for the fluid data and grid.
 * 
 * Author: M A Nawaz (ali.nawaz.md@gmail.com) 
 * Date: 26 March 2017 
 * File created on: 2017-04-03 09:10:18.000 
 * ------------------------------------------------------------------------- */
/* ------------------------ MACROS for GRID --------------- */
#define IBEG 2
#define IEND 101
#define JBEG 2
#define JEND 101
#define KBEG 0
#define KEND 0
#define NX1_TOT 104
#define NX2_TOT 104
#define NX3_TOT 1
#define NX1 100
#define NX2 100
#define NX3 1



/* ----------------- MACROS from problem setup ------------- */
#define DIMENSIONS 2
#define COMPONENTS 3

/* Manual Input- PHYSICS: HD / RHD / MHD / RMHD ? */
#define PHYSICS 

/* Manual Input- GEOMETRY: CARTESIAN / CYLINDRICAL / POLAR / SPHERICAL ? */
#define GEOMETRY 



/* ----------------- Physics modules' label ------------- */
#define HD 2
#define RHD 3
#define MHD 4
#define RMHD 5



/* ----------------- Geometry label ------------- */
#define CARTESIAN 1
#define CYLINDRICAL 2
#define POLAR 3
#define SPHERICAL 4



#define NVAR  10



#define  RHO   0
#define  VX1   1
#define  VX2   2
#define  VX3   3
#define  BX1   4
#define  BX2   5
#define  BX3   6
#define  PRS   7
/* Manual Input- TRACER */
#define  TRC   8
#define  TRC1 9
