#include <bits/stdc++.h>

using namespace std;
                    


//----------------------Hashmap + Backtrack Method (Best)----------------------------
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {   // base case, it means we have placed all the queens in the board in the safe position
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {

        // checking if the position is safe to place the queen in leftrow, upperDiagonal, lowerDiagonal
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';  // placing the queen
          leftrow[row] = 1;      // marking the position as visited
          lowerDiagonal[row + col] = 1;  // marking the position as visited
          upperDiagonal[n - 1 + col - row] = 1;  // marking the position as visited

          //this is the recursive call
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n); // calling the function for next column 


            //backtracking now 
          board[row][col] = '.';  // removing the queen
          leftrow[row] = 0;     // marking the position as unvisited
          lowerDiagonal[row + col] = 0;    // marking the position as unvisited
          upperDiagonal[n - 1 + col - row] = 0;   // marking the position as unvisited
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      // creating 3 vectors to store the positions of queens in the columns and diagonals
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

// Time Complexity: Exponential in nature since we are trying out all ways, 
// to be precise it is O(N! * N).

// Space Complexity: O(N)




//------------------Only Backtracking Method (Good)------------------


class Solution {
  public:
    // Function to check if a position (row, col) is safe to place a queen
    bool isSafe1(int row, int col, vector < string > board, int n) {
      // Check upper-left diagonal
      int duprow = row;
      int dupcol = col;
      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }
      
      // Check left column
      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }
      
      // Check lower-left diagonal
      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true;
    }

    // Function to find all possible arrangements of queens
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
      // If all columns have a queen, add the arrangement to the answer
      if (col == n) {
        ans.push_back(board);
        return;
      }
      // Try each row in the current column
      for (int row = 0; row < n; row++) {
        // If the position (row, col) is safe, place a queen and move to the next column
        if (isSafe1(row, col, board, n)) {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.';
        }
      }
    }

    // Function to solve the N-Queens problem
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      // Create an NxN board filled with dots
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      // Call the solve function to find all possible solutions
      solve(0, board, ans, n);
      return ans;
    }
};

int main() {
  int n = 4; // We are taking a 4x4 grid and 4 queens
  Solution obj;
  // Call the solveNQueens function to find all possible solutions
  vector < vector < string >> ans = obj.solveNQueens(n);
  // Print all the solutions
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
  }
    cout << endl;
  }
  return 0;
}


// OUTPUT:
// Arrangement 1
// ..Q.
// Q...
// ...Q
// .Q..

// Arrangement 2
// .Q..
// ...Q
// Q...
// ..Q.

// Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O

// (N! * N) nearly.

// Space Complexity: O(N^2)


