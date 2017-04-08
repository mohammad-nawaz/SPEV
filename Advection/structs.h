/* -----------------------------------------------------------------------------
 * Declaration of structures for SPEV.
 *  Structures that have names starting with BG are required to retrieve the 
 *  background fluid data produced by PLUTO. 
 * Author: M A Nawaz (ali.nawaz.md@gmail.com)
 * Date: 18 March 2017
 * -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
 * This structure is required to retrieve the background fluid data.
 * The name of the members and their data type is same as in the PLUTO.
 * Ref. PLUTO struct DATA
 * -------------------------------------------------------------------------- */
typedef struct BG_DATA{
    double ****Vc; /* Vc[nv][k][j][i] */
    double ****Vuser; /* Vuser[nv][k][j][i] */
    double ***Ax1; // Not clear yet. 
    double ***Ax2; // Q.Why triple pointer is required 
    double ***Ax3; // for a single component?
    double ****J;  // Not clear yet.
    char   fill[16];    /* This is required to make the structure size a power of 2 */
} Bg_Data;


/* -----------------------------------------------------------------------------
 * This structure is required to retrieve the background fluid data.
 * The name of the members and their data type is same as in the PLUTO.
 * Ref. PLUTO struct OUTPUT
 * -------------------------------------------------------------------------- */
typedef struct BG_INPUT{
  int    nvar;            /* Total number of variables */
  char   **var_name;      /* Name of the variables */
  double ***V[64];     /* pointer to arrays */ 
  char   fill[496];    /* This is required to make the structure size a power of 2 */
} Bg_Input;

/* -----------------------------------------------------------------------------
 * Structure required to retrieve the background GRID. This structure is taken
 * from PLUTO source code. 
 * Ref: PLUTO struct GRID
 * -------------------------------------------------------------------------- */
typedef struct BG_GRID{
  double xi, xf;        /**< Leftmost and rightmost point in the local domain. */
  double *x, *x_glob;   /**< Cell geometrical central points. */
  double *xr, *xr_glob; /**< Cell right interface. */
  double *xl, *xl_glob; /**< Cell left interface. */
  double *dx, *dx_glob; /**< Cell size.  */ 
  double *xgc;          /**< Cell volumetric centroid 
                             (!= x when geometry != CARTESIAN).  */
  double *dV;           /**< Cell volume.  */
  double *A;            /**< Right interface area, A[i] = \f$A_{i+\HALF}\f$. */
  double *r_1;          /**< Geometrical factor 1/r.  */
  double *ct;           /**< Geometrical factor cot(theta).  */
  double *inv_dx;       /**<      */
  double *inv_dxi;      /**< inverse of the distance between the center of 
                             two cells, inv_dxi = \f$\DS \frac{2}{\Delta x_i +
                             \Delta x_{i+1}}\f$.     */
  double dl_min;      /**<  minimum cell length (e.g. min[dr, r*dth,
                            r*sin(th)*dphi] (GLOBAL DOMAIN).  */
  int np_tot_glob; /**< Total number of points in the global domain 
                        (boundaries included). */
  int np_int_glob; /**< Total number of points in the global domain 
                        (boundaries excluded). */
  int np_tot;      /**< Total number of points in the local domain 
                        (boundaries included). */
  int np_int;      /**< Total number of points in the local domain 
                        (boundaries excluded). */
  int nghost;      /**< Number of ghost zones. */
  int lbound;      /**< When different from zero, it specifies the boundary
                        condition to be applied at leftmost grid side where  
                        the physical boundary is located.
                        Otherwise, it equals zero if the current 
                        processor does not touch the leftmost physical boundary. 
                        This evantuality (lbound = 0) is possible only
                        in PARALLEL mode.  */
  int rbound;      /**< Same as lbound, but for the right edge of the grid. */
  int gbeg;        /**< Global start index for the global array. */
  int gend;        /**< Global end   index for the global array. */
  int beg;         /**< Global start index for the local array. */
  int end;         /**< Global end   index for the local array. */
  int lbeg;        /**< Local start  index for the local array. */
  int lend;        /**< Local end    index for the local array. */
  int uniform;     /* = 1 when the grid is cartesian AND uniform everywhere  */
  int nproc;       /**< number of processors for this grid. */
  int rank_coord;  /**< Parallel coordinate in a Cartesian topology. */
  int level;       /**< The current refinement level (chombo only). */
  char fill[40];   /* useless, just to make the structure size a power of 2 */
} Bg_Grid; 



/* -----------------------------------------------------------------------------
 * Data structure for Lagrangian Particles 
 * -------------------------------------------------------------------------- */
typedef struct LP_DATA{
    double **Vp;  /* Position and ID of Lagrangian Partices: Vp[id][x] 
		   * id will run from 0 to no. of particles NPAR.
		   * x will run from 0 to 1 (2D) or 0 to 2 (3D). */
} Lp_Data;


/* -----------------------------------------------------------------------------
 * 
 * -------------------------------------------------------------------------- */
typedef struct LP_OUTPUT{
    int npar; 
    double *V[60];
    char   fill[24];    /* This is required to make the structure size a power of 2 */
} Lp_Output;

