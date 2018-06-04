/*
-------------- N Queen Problem -----------

Place N chess queens on an N×N chessboard so that no two queens attack each other either horizontally, or vertically, or diagonally.
*/

#include <iostream>

#define N 4

static int tot_sol = 0;

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

void solveNQueen(int board[N][N], int row)
{
    if (row == N){
        std::cout << "\nSolution number: " << ++tot_sol << std::endl;
        printSolution(board);
    }

    for (int i=0; i<N; i++){
        if(isSafe(board, row, i)){
            board[row][i] = true;
            solveNQueen(board, row + 1);
            board[row][i] = false;                // Backtrack
        }
    }
}

int main()
{
    int board[N][N] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}
    };

    solveNQueen(board, 0);

    if(tot_sol == 0){
        std::cout << "No solution exist." << std::endl;
    }

    return 0;
}