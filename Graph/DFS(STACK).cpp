// C++ program to print DFS
// traversal for a given
// graph
#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';

class Graph {

    // A function used by DFS
    void DFSUtil(int v);

public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    // function to add an edge to graph
    void addEdge(int v, int w);
    void print_map();
    // prints DFS traversal of the complete graph
    void DFS();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}


void print_map(map<int, list<int> > adj){
    cout << "Map: " << endl;
    for (auto itr : adj){
        cout << itr.first << ":\t";
        for (auto innerItr : itr.second)
            cout << innerItr << " ";
        cout << endl;
    }
}
void Graph::DFSUtil(int v)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout<<nl<<"print " << v << " ";


    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;  //auto i
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
       
        cout<<nl<<"checking: "<<endl;
        if (!visited[*i]){
            cout<<"call again DFSUtil: "<<visited[*i]<<endl;
            DFSUtil(*i);
        }
        else cout<<"skip/over"<<nl;
    }
}

// The function to do DFS traversal. It uses recursive
// DFSUtil()
void Graph::DFS()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (auto i : adj){
        if (visited[i.first] == false){
            cout<< "dfs1 calll: "<<i.first<<endl;
            DFSUtil(i.first);
        }}
}

// Driver's Code
int main()
{
    // Create a graph given in the above diagram
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);




    
    print_map(g.adj);
    // Function call
    
    cout << "Following is Depth First Traversal \n";
    g.DFS();
    

    return 0;
}
// improved by Vishnudev C
