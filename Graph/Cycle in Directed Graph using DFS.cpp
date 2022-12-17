By Striver 


#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[node] = 1;
      dfsVis[node] = 1;
      for (auto it: adj[node]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[node] = 0;
      return false;
    }
  public:
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
     
      for(int i = 0; i < N; i++){
        vis[i] = 0;
        dfsVis[i] = 0;
      }

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          // cout << i << endl; 
          if (checkCycle(i, adj, vis, dfsVis)) {
             // cout << i << endl;
            return true;
          }
        }
      }
      return false;
    }
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
}

int main() {

  int V = 6;

  vector < int > adj[V];
  addEdge(adj, 0, 1);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 5);
  addEdge(adj, 2, 3);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 0);
  addEdge(adj, 4, 1);
  

  Solution obj;
  if (obj.isCyclic(V, adj))
    cout << "Cycle Detected" << "\n";
  else
    cout << "No Cycle Detected";

  return 0;
}

------------------------------------------------------------------------------------------------------------------------------------
  
                                                       Java
                                                       
import java.util.*;

class GFG {
        	
    public static void main (String[] args) {
                    	
                    	int V= 6;
                    	ArrayList<ArrayList<Integer>> graph = new ArrayList<>(V);
       
                    	//Vertex - 0
                    	ArrayList<Integer> neighbors = new ArrayList<Integer>();
                    	neighbors.add(1);
                    	graph.add(neighbors);
 
                    	//Vertex - 1
                    	neighbors = new ArrayList<Integer>();
                    	neighbors.add(2);
                    	neighbors.add(5);
                    	graph.add(neighbors);
 
                    	//Vertex - 2
                    	neighbors = new ArrayList<Integer>();
                    	neighbors.add(3);
                    	graph.add(neighbors);
 
                    	//Vertex - 3
                    	neighbors = new ArrayList<Integer>();
                    	neighbors.add(4);
                    	graph.add(neighbors);
 
                    	//Vertex - 4
                    	neighbors = new ArrayList<Integer>();
                    	neighbors.add(0);
                    	neighbors.add(1);
                    	graph.add(neighbors);
 
                    	//Vertex - 5
                    	neighbors = new ArrayList<Integer>();
                    	graph.add(neighbors);
                    	
                    	if(isCyclic(V, graph))
                         System.out.println("Cycle detected");
                    	else
                         System.out.println("No cycles detected");
 
    }
 
    private static boolean checkCycle(int node,  ArrayList<ArrayList<Integer>> adj, int vis[], int dfsVis[]) {
        vis[node] = 1;
        dfsVis[node] = 1;
       
        for(Integer neighbor: adj.get(node)) {
        	if(vis[neighbor] == 0) {
                if(checkCycle(neighbor, adj, vis, dfsVis) == true) {
                	return true;
            	}
        	} else if(dfsVis[neighbor] == 1) {
            	return true;
        	}
        }
        dfsVis[node] = 0;
        return false;
    }
        	
    public static boolean isCyclic(int N, ArrayList<ArrayList<Integer>> adj) {
        int vis[] = new int[N];
        int dfsVis[] = new int[N];
       
        for(int i = 0;i<N;i++) {
        	if(vis[i] == 0) {
                if(checkCycle(i, adj, vis, dfsVis) == true) return true;
        	}
        }
        return false;
    }
}                                                       
  
  
  
