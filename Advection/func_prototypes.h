/* -----------------------------------------------------------------------------
 * Description: Function prototypes of spev
 * Author: M A Nawaz (ali.nawaz.md@gmail.com)
 * Date: 14 March 2017
 * -------------------------------------------------------------------------- */
int FileLines(char *);
int FileLineWords(char *, char **);
char *FileParamVals(char *, int );
void GetPlutoVarNames(Bg_Input *);
FILE *OpenBinaryFile (char *, char *);

char *SinglePtr (int , size_t );
char **DoublePtr (int, int, size_t);
char ****QuadruplePtr (int, int,int, int,  size_t);

void ReadBinaryFile (void *, size_t, FILE *);
void SetBackground ();

#define SPtr(nx, type)   (type *)SinglePtr(nx, sizeof(type)) 
#define DPtr(nx, ny, type)   (type **)DoublePtr(nx, ny, sizeof(type)) 
#define QPtr(nx, ny, nz, nv, type)   (type ****)QuadruplePtr(nx, ny, nz, nv, sizeof(type)) 
