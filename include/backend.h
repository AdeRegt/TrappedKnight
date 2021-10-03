
/**
 * Initialises the backend.
 * @param boardsize_v Set the preffered boardsize
 * @returns 0 on success, 1 on failure
 *  **/
int initialise_backend(int boardsize_v);

/** 
 * Calculates the array possition based on the x and y input
 * @param x the x location
 * @param y the y location
 * @returns the array location 
 **/
int calculate_x_y_to_cell_location(int x,int y);

/** 
 * Dumps the contents of the 
 **/
void dump_board();

/** 
 * The cell object
 **/
typedef struct gridcell_t{
    /** 
     * The value of the cell
     **/
    int cellvalue;
    /** 
     * If the cell is visited, the value is 1, otherwise 0
     **/
    unsigned char is_visited;
    /** 
     * Link to our previous cell
     **/
    gridcell_t *previous_visit;
}GridCell;