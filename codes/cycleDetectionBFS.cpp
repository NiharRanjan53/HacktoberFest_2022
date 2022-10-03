#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
//cyclic detection function
bool isCyclic(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int> > &adjList){
    //sabse phle ek parent DS bnao
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;    //mark visited
    queue<int> q;
    //push source to queue
    q.push(src);
    
    while(!q.empty()){
        //front node nikalo
        int frontNode = q.front();
        q.pop();
        //neighbours nikalo uske
        for(auto neighbour : adjList[frontNode]){
            //cycle kab present hogi agar visited hoga or parent nhi ho
            if(visited[neighbour] == true && neighbour != parent[frontNode]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
    
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int> > adjList;
    //create adjacency list
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int,bool> visited;
    //to handle disconnected component
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCyclic(i,visited,adjList);
            if(ans == 1){
                return "Yes";
            }
        }
        
    }
    return "No";
}
