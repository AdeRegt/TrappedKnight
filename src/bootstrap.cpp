#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "../include/bootstrap.h"
#include "../include/backend.h"

int main(int argc,char** argv){
    printf("Welcome to TrappedKnight.\n");
    printf("Program is initialised with %i parameters.\n",argc);
    int boardsize = DEFAULT_BOARD_SIZE;
    for(int i = 1 ; i < argc ; i++){
        //
        // parsing here the size of certain objects
    }

    //
    // here the start of the backend
    if(initialise_backend(boardsize)){
        return EXIT_FAILURE;
    }

    //
    // here the start of the frontend

    return EXIT_SUCCESS;
}