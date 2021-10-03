/**
* Our main function
* @param argc The amount of arguments passed to the function
* @param argv The parameters themselves
* @returns EXIT_SUCCESS when the program has no errors, EXIT_FAILURE otherwise
**/
int main(int argc,char** argv);

/**
 * Sets the default size of the board
 **/
#define DEFAULT_BOARD_SIZE 11

#if !(DEFAULT_BOARD_SIZE%2) 
    #error You should use a odd boardsize
#endif