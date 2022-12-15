#include<bits/stdc++.h>
using namespace std;
const char nl ='\n';
/* Function to add an Edge */
void Edge(vector<int> adj[], int v1, int v2)
{
    /* considering undirected graph, hence adding both forward and backward edge */
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
    
}

void print_Edge(vector<int> adj[])
{  //Printing Array of Vectors
    for(int i=0; i<7; i++)
    {
        cout<<nl<<"Adjacency List of vertex "<<i<<": ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<", ";
        }
        cout<<nl;
    }
}

/* Simple BFS Function */
void BFS(int v1, vector<int> adj[], vector<bool> &Visited)
{   cout<<"BFS called for: "<<v1<<endl;
    /* Initialize a queue for keeping track of upcoming vertices */
    list<int> queue_of_vertices;
 
    /* Mark the current vertex visited and pushed to the queue*/
    Visited[v1] = true;
    queue_of_vertices.push_back(v1);
 
    /* while the queue is not empty, keep on traversing */
    while(!queue_of_vertices.empty())
    {
        /* remove the front vertex and print it*/
        v1 = queue_of_vertices.front();
        cout<<nl <<"OutPut :"<< v1 << nl;
        queue_of_vertices.pop_front();
 
        /* Add all the unvisited adjacent vertices of v1 to the queue */
        for (int iter = 0; iter != adj[v1].size(); iter++)
        {
            if (!Visited[adj[v1][iter]])
            {
                Visited[adj[v1][iter]] = true;
                cout<<" iter= "<<iter<<"  calling for: "<<adj[v1][iter]<<endl;
                queue_of_vertices.push_back(adj[v1][iter]);
            }
        }
    cout<<"cureent queue: "<<endl;
    for (auto itr : queue_of_vertices)
        cout<<itr<<" ";
    cout<<endl;

    }
}
 
/* Driver Function */
int main()
{
    int number_of_vertices = 7;
    vector<int> adj[number_of_vertices];
 
    /* Adding edges */
    Edge(adj, 0, 1);
    Edge(adj, 0, 2);
    Edge(adj, 1, 2);
    Edge(adj, 1, 3);
    Edge(adj, 2, 3);
    Edge(adj, 4, 5);
    Edge(adj, 4, 6);
    print_Edge(adj);
   
    vector<bool> Visited(number_of_vertices, false);
    for (int u=0; u<number_of_vertices; u++)
        if (Visited[u] == false){
            cout<<"from main calling for: "<<u<<endl;
            BFS(u, adj, Visited);
        }
    return 0;
}


OUTPUT:
Adjacency List of vertex 0: 1, 2, 

Adjacency List of vertex 1: 0, 2, 3,

Adjacency List of vertex 2: 0, 1, 3,

Adjacency List of vertex 3: 1, 2,

Adjacency List of vertex 4: 5, 6,

Adjacency List of vertex 5: 4,

Adjacency List of vertex 6: 4,
from main calling for: 0
BFS called for: 0

OutPut :0
 iter= 0  calling for: 1
 iter= 1  calling for: 2
cureent queue:
1 2

OutPut :1
 iter= 2  calling for: 3
cureent queue:
2 3

OutPut :2
cureent queue:
3

OutPut :3
cureent queue:

from main calling for: 4
BFS called for: 4

OutPut :4
 iter= 0  calling for: 5
 iter= 1  calling for: 6
cureent queue:
5 6

OutPut :5
cureent queue:
6

OutPut :6
cureent queue:
