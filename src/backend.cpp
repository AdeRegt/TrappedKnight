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

int* calculate_cell_to_x_y_location(int startingcell){
    int *ab = (int*) malloc(sizeof(int)*2);
    int y = startingcell/boardsize;
    int x = startingcell - (y*boardsize);
    ab[0] = x;
    ab[1] = y;
    return ab;
}

int get_possible_cell_to_jump(int startingcell){
    int *data = calculate_cell_to_x_y_location(startingcell);
    int x = data[0];
    int y = data[1];
    int res = -1;

    // 2 on top
    GridCell gc1 = cells[calculate_x_y_to_cell_location(x-1,y-2)];
    GridCell gc2 = cells[calculate_x_y_to_cell_location(x+1,y-2)];
    // 2 right
    GridCell gc3 = cells[calculate_x_y_to_cell_location(x+2,y-1)];
    GridCell gc4 = cells[calculate_x_y_to_cell_location(x+2,y+1)];
    // 2 left
    GridCell gc5 = cells[calculate_x_y_to_cell_location(x-2,y-1)];
    GridCell gc6 = cells[calculate_x_y_to_cell_location(x-2,y+1)];
    // 2 bottom
    GridCell gc7 = cells[calculate_x_y_to_cell_location(x-1,y+2)];
    GridCell gc8 = cells[calculate_x_y_to_cell_location(x+1,y+2)];

    int maxcal = boardsize;
    if(gc1.is_visited==0&&gc1.cellvalue<maxcal){
        maxcal=gc1.cellvalue;
        res = calculate_x_y_to_cell_location(x-1,y-2);
    }
    if(gc2.is_visited==0&&gc2.cellvalue<maxcal){
        maxcal=gc2.cellvalue;
        res = calculate_x_y_to_cell_location(x+1,y-2);
    }
    if(gc3.is_visited==0&&gc3.cellvalue<maxcal){
        maxcal=gc3.cellvalue;
        res = calculate_x_y_to_cell_location(x+2,y-1);
    }
    if(gc4.is_visited==0&&gc4.cellvalue<maxcal){
        maxcal=gc4.cellvalue;
        res = calculate_x_y_to_cell_location(x+2,y+1);
    }
    if(gc5.is_visited==0&&gc5.cellvalue<maxcal){
        maxcal=gc5.cellvalue;
        res = calculate_x_y_to_cell_location(x-2,y-1);
    }
    if(gc6.is_visited==0&&gc6.cellvalue<maxcal){
        maxcal=gc6.cellvalue;
        res = calculate_x_y_to_cell_location(x-2,y+1);
    }
    if(gc7.is_visited==0&&gc7.cellvalue<maxcal){
        maxcal=gc7.cellvalue;
        res = calculate_x_y_to_cell_location(x-1,y+2);
    }
    if(gc8.is_visited==0&&gc8.cellvalue<maxcal){
        maxcal=gc8.cellvalue;
        res = calculate_x_y_to_cell_location(x+1,y+2);
    }

    return res;

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