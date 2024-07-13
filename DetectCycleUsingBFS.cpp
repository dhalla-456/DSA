#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<stack>
using namespace std;

int topologicalSort(vector<vector<int>> &edges,int n)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i][0]; // agr node 1 se start h to int u = edges[i][0]-1;
        int v = edges[i][1]; // int v = edges[i][1]-1;

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(n);
    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    //0 degree walo ko queue m push kro

    queue<int> q;
    for(int i = 0;i<n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //Do BFS
    vector<int> ans;
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        
        //increment in count
        count = 0;

        //ans Store kro
        ans.push_back(front);

        //neighbour indegree update
        for(auto i : adj[front])
        {
            indegree[i]--;
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

    }
    
    if (count == n) 
    {
        return false; //agr topologicalSort shi h to node print hongi vo equal hongi acyclic hoga is liye
    }
    else
    {
        return true; //cyclic h isliye count  != n hoga
    }
}
