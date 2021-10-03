#include <stdio.h>
#include <stdlib.h>

#include "../include/backend.h"

/**
 * The board
 **/
GridCell *cells;

/** 
 * The size of the board in one direction
 **/
int boardsize = 0;

int calculate_x_y_to_cell_location(int x,int y){
    int result = 0;
    result += y*boardsize;
    result += x;
    return result;
}

void dump_board(){
    for(int y = 0 ; y < boardsize ; y++){
        for(int x = 0 ; x < boardsize ; x++){
            int g = cells[calculate_x_y_to_cell_location(x,y)].cellvalue;
            if(g>999){
                printf("%i ",g);
            }else if(g>99){
                printf(" %i ",g);
            }else if(g>9){
                printf("  %i ",g);
            }else{
                printf("   %i ",g);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int initialise_backend(int boardsize_v){
    boardsize = boardsize_v;

    //
    // lets check our inputvalues first
    // the boardsize must be odd
    if(!(boardsize%2)){
        printf("Boardsize is not odd. Use a odd boardsize\n");
        return 1;
    }

    //
    // Create the board
    cells = (GridCell*) malloc(sizeof(GridCell)*(boardsize*boardsize));
    // find the center of the board
    int centerpiece = (int)(boardsize/2);
    int cv = 1;
    // and place a 1 there
    cells[calculate_x_y_to_cell_location(centerpiece,centerpiece)].cellvalue = cv;
    cv++;
    // and fill the rest
    for(int t = 1 ; t < (centerpiece+1) ; t++){
        cells[calculate_x_y_to_cell_location(centerpiece+t,centerpiece+t)].cellvalue = cv;
        cv++;
        // right
        for(int z = 0 ; z < (t*2) ; z++){
            cells[calculate_x_y_to_cell_location(centerpiece+t,(centerpiece+t)-(z+1))].cellvalue = cv;
            cv++;
        }
        // top
        for(int z = 0 ; z < (t*2) ; z++){
            cells[calculate_x_y_to_cell_location((centerpiece+t)-(z+1),(centerpiece+t)-((t*2)))].cellvalue = cv;
            cv++;
        }
        // left
        for(int z = 0 ; z < (t*2) ; z++){
            cells[calculate_x_y_to_cell_location(centerpiece-t,(centerpiece-t)+(z+1))].cellvalue = cv;
            cv++;
        }
        // bottom
        for(int z = 0 ; z < (t*2)-1 ; z++){
            cells[calculate_x_y_to_cell_location((centerpiece-t)+(z+1),(centerpiece-t)+((t*2)))].cellvalue = cv;
            cv++;
        }
    }

    // check if all is oke
    dump_board();

    return 0;
}