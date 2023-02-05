
// } Driver Code Ends
// User function template for C++
class Solution {
  void solve(int i, int j, vector < vector < int >> & a, int n, vector < string > & ans, string move,
    vector < vector < int >> & vis, int di[], int dj[]) {
    // if the current cell is the bottom-right cell
    if (i == n - 1 && j == n - 1) {
      // add the path to the result vector
      ans.push_back(move);
      return;
    }
    // the array of direction letters
    string dir = "DLRU";
    // loop through all the 4 possible directions
    for (int ind = 0; ind < 4; ind++) {
      // calculate the next cell in the current direction
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      // if the next cell is inside the matrix and not visited and the value of the cell is 1
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        // mark the current cell as visited
        vis[i][j] = 1;
        // recursively call the solve function with the next cell and the updated path
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        // backtracking by unmarking the current cell as visited
        vis[i][j] = 0;
      }
    }

  }
  public:
    vector < string > findPath(vector < vector < int >> & m, int n) {
      // the result vector
      vector < string > ans;
      // the 2D boolean array to keep track of visited cells
      vector < vector < int >> vis(n, vector < int > (n, 0));
      
      
      // the arrays of possible changes in row and column indices
      int di[] = {+1,0,0,-1};
      int dj[] = {0,-1,+1,0};
        
      // if the value of the top-left cell is 1, call the solve function, 
      // atleast start node should be 1
      if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
      // return the result vector
      return ans;
    }
};

// Time Complexity: O(4^(m*n)), because on every cell 
// we need to try 4 different directions.

// Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space).


//{ Driver Code Starts.
