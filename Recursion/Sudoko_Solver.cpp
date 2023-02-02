#include <iostream>
#include <vector>
using namespace std;
//------------------------------STRIVER + BACKTRACK----------------

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
      solve(board);
    }

    
// Solve the sudoku puzzle using backtracking
bool solve(vector < vector < char >> & board) {
  // Iterate through all cells of the board
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      // If the cell is empty
      if (board[i][j] == '.') {
        // Try to fill the cell with characters '1' to '9'
        for (char c = '1'; c <= '9'; c++) {
          // Check if the character 'c' is valid
          if (isValid(board, i, j, c)) {
            // Set the cell to the character 'c'
            board[i][j] = c;
            // Recursively solve the rest of the puzzle
            if (solve(board))
              return true;
            else
              // Backtrack
              board[i][j] = '.';
          }
        }
        // If no solution is found, return false
        return false;
      }
    }
  }
  // If all cells have been filled, return true
  return true;
}

//Check if the character 'c' is valid at the current cell (row, col)
bool isValid(vector < vector < char >> & board, int row, int col, char c) {
  // Check if 'c' exists in the same column
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == c)
      return false;
  }

  // Check if 'c' exists in the same row
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == c)
      return false;
  }

  // Check if 'c' exists in the same 3x3 sub-grid
  for (int i = 0; i < 9; i++) {
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
      return false;
  }
  // If 'c' is not found in the same column, row or sub-grid, return true
  return true;
}



};

int main() {
  Solution obj;
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };
   
    obj.solveSudoku(board);
          
    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}

// OUTPUT:
// 9 5 7 6 1 3 2 8 4 
// 4 8 3 2 5 7 1 9 6 
// 6 1 2 8 4 9 5 3 7 
// 1 7 8 3 6 4 9 5 2 
// 5 2 4 9 7 1 3 6 8 
// 3 6 9 5 2 8 7 4 1 
// 8 4 5 7 9 2 6 1 3 
// 2 9 1 4 3 6 8 7 5 
// 7 3 6 1 8 5 4 2 9 
