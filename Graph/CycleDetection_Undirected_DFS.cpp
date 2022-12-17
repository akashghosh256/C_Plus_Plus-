//Cycle Detection in Undirected Graph using DFS----Striver

#include<bits/stdc++.h>
using namespace std;

class solution{

public:
bool checkforcycle(int node , int parent, vector<int> &vis , vector <int> adj[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkforcycle(it,node,vis,adj))
            return true;
        }
        else if(it!=parent)
        return true;

    }
    return false;
}

public:

bool isCycle(int v, vector<int>adj[]){

vector<int>vis(v+1,0);


for(int i=0; i<v ;i++)
{
    if(!vis[i]){
        if(checkforcycle(i,-1,vis,adj))  return true;
    }    
}
return false;
}};


int main(){
    int v=5;
    int e =5;
    vector<int>adj[v];

  adj[0].push_back(1);
  adj[1].push_back(0);

  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[1].push_back(4);
  adj[4].push_back(1);

  adj[4].push_back(3);
  adj[3].push_back(4);

  adj[2].push_back(3);
  adj[3].push_back(2);

solution obj;
bool ans = obj.isCycle(v,adj);
if(ans){
    cout<<"Cycle detected";

}
else cout<<"No cycle is detected";
return 0;

}
//---------------------------------------------------------------------------------------------------------------------------------------

                    JAVA CODE
import java.util.*;
class GFG {
    public static void main(String[] args) {


        int V = 5;

        ArrayList < ArrayList < Integer >> adj = new ArrayList < > ();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList < > ());
        }
        // edge 0---1
        adj.get(0).add(1);
        adj.get(1).add(0);

        // edge 1---2
        adj.get(1).add(2);
        adj.get(2).add(1);

        // adge 2--3
        adj.get(2).add(3);
        adj.get(3).add(2);

        // adge 3--4
        adj.get(3).add(4);
        adj.get(4).add(3);

        // adge 1--4
        adj.get(1).add(4);
        adj.get(4).add(1);


        Solution obj = new Solution();
        boolean ans = obj.isCycle(V, adj);
        if (ans == true) {
            System.out.println("Cycle Detected");
        } else {
            System.out.println("No Cycle Detected");

        }
    }
}


class Solution {
    public boolean checkForCycle(int node, int parent, boolean vis[], ArrayList < ArrayList 
    < Integer >> adj) {
        vis[node] = true;
        for (Integer it: adj.get(node)) {
            if (vis[it] == false) {
                if (checkForCycle(it, node, vis, adj) == true)
                    return true;
            } else if (it != parent)
                return true;
        }

        return false;
    }
    // 0-based indexing Graph
    public boolean isCycle(int V, ArrayList < ArrayList < Integer >> adj) {
        boolean vis[] = new boolean[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == false) {
                if (checkForCycle(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }
}
