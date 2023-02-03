#include<bits/stdc++.h>

using namespace std;

// Function to check if it's safe to color a node with a given color
bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
  // Loop through all nodes connected to the current node
  for (int k = 0; k < n; k++) {
    // If the node is connected and has the same color, return false
    if (k != node && graph[k][node] == 1 && color[k] == col) {
      return false;
    }
  }
  return true;
}

// Recursive function to solve the graph coloring problem
bool solve(int node, int color[], int m, int N, bool graph[101][101]) {
  // If all nodes have been colored, return true
  if (node == N) {
    return true;
  }

  // Try coloring the current node with each color
  for (int i = 1; i <= m; i++) {
    // If the color is safe for the current node
    if (isSafe(node, color, graph, N, i)) {
      // Assign the color
      color[node] = i;
      // Move to the next node
      if (solve(node + 1, color, m, N, graph)) return true;
      // Backtrack if the coloring isn't valid
      color[node] = 0;
    }
  }
  // If no coloring is valid, return false
  return false;
}

// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  // Initialize the color array with all nodes uncolored
  int color[N] = {0};
  // Call the solve function and return its result
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4; // Number of nodes in the graph
  int m = 3; // Number of colors

//   Initialize the graph adjacency matrix
//   The graph is declared as a two-dimensional boolean 
//   array of size 101 x 101 because the number of vertices 
//   in the graph is specified to be at most 100. 
//   By declaring the array size one larger in each 
//   dimension, this allows for the use of indices starting 
//   from 0 to 100. This is a common practice in C/C++ to simplify 
//   indexing when arrays have a maximum size that is not equal to 
//   their largest index.

  bool graph[101][101];
//  memset() is a C/C++ function that fills a block of memory 
//  with a particular value.
  memset(graph, false, sizeof graph);  // Fill the graph with false`

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  // The graph is undirected, so the edges are bidirectional
  // Filling the graph with 1/True at the corresponding positions
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  // Call the graphColoring function and print the result
  cout << graphColoring(graph, m, N);

}
