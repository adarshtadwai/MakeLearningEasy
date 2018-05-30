/*
-------------- N Queen Problem -----------

Place N chess queens on an N×N chessboard so that no two queens attack each other either horizontally, or vertically, or diagonally.
*/

#include <iostream>

#define N 4

void printSolution(int board[N][N])
{
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isSafe(int board[N][N], int row, int col)
{
    for(int i=0; i<row; i++){                         // Check the column
        if(board[i][col])   
            return false;
    }

    int i, j;
    for(i=row, j=col; i>=0 && j>=0; i--, j--){        // Check upper left diagonal
        if(board[i][j]) 
            return false;
    }

    for(i=row, j=col; i>=0 && j<N; i--, j++){         // Check upper right diagonal
        if(board[i][j]) 
            return false;
    }

    return true;
}

bool solveNQueen(int board[N][N], int row)
{
    if (row >= N)
        return true;

    for (int i=0; i<N; i++){
        if(isSafe(board, row, i)){
            board[row][i] = true;

            if(solveNQueen(board, row+1))
                return true;
        
            board[row][i] = false;                // Backtrack
        }
    }

    return false;
}

int main()
{
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}
    };

    if(solveNQueen(board, 0) == false){
        std::cout << "No solution exist." << std::endl;
        return 0;
    }

    printSolution(board);

    return 0;
}