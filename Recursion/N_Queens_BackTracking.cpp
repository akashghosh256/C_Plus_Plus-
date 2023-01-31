#include <bits/stdc++.h>

using namespace std;

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