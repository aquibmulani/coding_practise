// Function to check a valid row in the sudoku board 
bool checkRow(char **board, int n)
{
    char boardstatus[10] = {0};
    for(int i =0; i < 9;i++)
    {
         char cell = board[n][i];
        if(board[n][i] != '.')
        {
            char idx = cell - '0';
            if(boardstatus[idx] == 0)
            {
                boardstatus[idx] = cell;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
// Function to check a valid column in the sudoku board
bool checkCol(char **board, int n)
{
    char boardstatus[10] = {0};
    for(int i =0; i < 9;i++)
    {
         char cell = board[i][n];
        if(board[i][n] != '.')
        {
            char idx = cell - '0';
            if(boardstatus[idx] == 0)
            {
                boardstatus[idx] = cell;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
    
}
// Function to check a valid 3X3  grid in the sudoku board
bool checkGrid(char **board, int n)
{
    char boardstatus[10] = {0};
    // Always start to the top left of the grid
    int row = (n /3) * 3;
    int col = (n % 3) * 3;
    for(int r = row; r < (row+3);r++)
    {
        for(int c = col; c < (col+3);c++)
        {
            char cell = board[r][c];
            if(board[r][c] != '.')
            {
              char idx = cell - '0';
              if(boardstatus[idx] == 0)
              {
                boardstatus[idx] = cell;
              }
              else
              {
                return false;
              }
        }
        }
    }
    return true;    
}



bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
   for(int n = 0; n < boardSize; n++){
        if( !checkRow(board, n)) return false;
        if( !checkCol(board, n)) return false;
        if ( !checkGrid(board, n)) return false;
    }
    return true;
}