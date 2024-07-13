#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<string>
using namespace std;

bool checkCycle(int node,unordered_map<int,bool> &visited,
                    unordered_map<int,bool> &DFSvisited,unordered_map<int,list<int>> &adj)
{
    visited[node] = 1;
    DFSvisited[node] = 1;

    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            bool detect = checkCycle(i, visited, DFSvisited, adj);
            if(detect)
            {
                return true;
            }
        }
        else if(visited[i] && DFSvisited[i])
        {
            return true;
        }
    }
    DFSvisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj list
  unordered_map<int,list<int>> adj;
  for(int i = 0 ;i<edges.size();i++)
  {
       int u = edges[i].first; 
       int v =edges[i].second;
      
       adj[u].push_back(v);
  }

  unordered_map<int,bool> visited;
  unordered_map<int,bool> DFSvisited;

  for(int i = 0;i<n;i++)
  {
      if(!visited[i])
      {
          bool cycleDetect = checkCycle(i,visited,DFSvisited,adj);
          if(cycleDetect)
          {
              return 1;
          }
      }
  }
  return 0;
}