/* -----------------------------------------------------------------------------
 * DESCRIPTION: spev main method
 *
 * AUTHOR: M A Nawaz(ali.nawaz.md@gmail.com)
 * DATE: 12 March 2017
 * -------------------------------------------------------------------------- */

#include "spev.h"


int main(){
    /* Clear screen */
    system("clear");

    Bg_Grid grid[3];

    // The following print statements are for structure alignment.
    printf("Size of bg_data: %lu\n", sizeof(Bg_Data));
    printf("Size of bg_input: %lu\n", sizeof(Bg_Input));
    printf("Size of bg_grid: %lu\n", sizeof(Bg_Grid));
    printf("Size of lp_data: %lu\n", sizeof(Lp_Data));
    printf("Size of lp_output: %lu\n", sizeof(Lp_Output));


    /* Program starts */
    printf("main.c/main(): Program starts ....\n");

    /* Set Background */
    //SetBackground(&bg_data);
    SetBackground();


    /* Set Grid */
  //  SetGrid(grid);
    SetGrid();

    /* Free all memories; This is a temporary location of freeing memories. */


    printf("Program quits ....\n");
    QUIT_SPEV(1);
    return 0;
}
