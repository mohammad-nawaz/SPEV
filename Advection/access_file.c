/* -----------------------------------------------------------------------------
 * DESCRIPTION: A set of functions required to access pluto.ini and spev.ini 
 * 	1. FileLines
 * 		Provide array of lines and return number of lines. 		
 *	2. FileLineWords
 *		Provide array of words for each line.
 * 	3. FileParamVals
 *		Return parameter value for a given parameter label.
 *
 * AUTHOR: M A Nawaz (ali.nawaz.md@gmail.com)
 * DATE: 27 March 2017
 * -------------------------------------------------------------------------- */
#include "spev.h"

static int nlines; 
static char **fline; 
static char **lword;

/* -------------------------------------------------------------------------- */
int FileLines(char * file_name)
/*
 * TASK: Provide array of lines for a given file and return number of files. 
 * PARAMETER: 
 *      file_name [in]: A file pointer for a given file. 
 *
 * RETURN: The number of lines in the given file
 * -------------------------------------------------------------------------- */
{
    FILE *fp;
    char sline[128];

    fp = fopen(file_name, "r");
    if(!fp){
	printf("File does not exist");
	exit(1);
    }

    /* Allocate memroy for array of lines */
    fline = DPtr(128, 64, char);

    /* Read entire file line by line at once */
    nlines=0;
    while (fgets(sline, 128, fp)){
//	puts(sline);
	strcpy(fline[nlines], sline);
	nlines++;
    }

    return nlines;
}

/* -------------------------------------------------------------------------- */
int FileLineWords(char *file_line, char **fline_word)
/*
 * TASK: Provide list of words for a given line/string of characters. 
 * PARAMETERS: 
 *      file_name  [in]: A pointer for a given line/string. 
 *  	fline_word [in]: A pointer for words in a line. 
 *
 * RETURN: The number of words in a given line.
 * -------------------------------------------------------------------------- */
{
    /* We use strtok to make array of words from a given line/string of 
     * characters. Since strtok edit the input string we copy the input 
     * line/string to a local variable. */
    char loc_line[64];
    int wc = 0; 
    
    /* Copy file line into the local line. */
    strcpy(loc_line, file_line); 



    /* Get tokens(words) separated by space form the local line. */
    fline_word[wc] = strtok(loc_line, " ");

    while (fline_word[wc] != NULL){
	printf("%s ", fline_word[wc]);
	fline_word[wc+1] = strtok(NULL, " ");
	wc++;
    }

    return wc;
}

/* -------------------------------------------------------------------------- */
char *FileParamVals(char *parlabel, int parloc)
/*
 * TASK: Provide value for a given parameter. 
 * PARAMETERS: 
 *      parlabel [in]: Lebel of a parameter whose value is seek.
 * 	parloc   [in]: Location of the parameter in the line. 
 *
 * RETURN: The value of a given parameter.
 * -------------------------------------------------------------------------- */
{
    int i;
    char **lword;

    /* Allocate memory for words of each line */
    lword = DPtr(16, 16, char);

    /* Search the parameter 'parlabel' in the file line by line. If found return
     * the value of the location 'parloc' */
    for (i=0; i < nlines; i++){
	FileLineWords(fline[i], lword); /* Get words for i-th line */

	/* Check for lword[0] and 'parlabel' match. */
	if (strcmp(lword[0], parlabel)==0)
	    break;
    }
    return lword[parloc];

    printf("access_file.c: FileParamVals \n");

}
