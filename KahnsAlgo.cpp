#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<stack>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges,int v , int e)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegree(v);
    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            indegree[j]++;
        }
    }

    //0 degree walo ko queue m push kro

    queue<int> q;
    for(int i = 0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //Do BFS
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

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
    return ans;
}
