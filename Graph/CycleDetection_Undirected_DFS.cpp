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
