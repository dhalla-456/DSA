#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;


void dfs(int node,unordered_map<int,bool> &visited,
            unordered_map<int,list<int>> &AdjList,vector<int> &component)
    {
        component.push_back(node);
        visited[node] = 1;

        //node se hr connected node ke liye recursive call
        for(auto i : AdjList[node])
        {
            if(!visited[i])
            {
                dfs(i,visited,AdjList,component);
            }
        }
    }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare AdjList
    unordered_map<int,list<int>> AdjList;
    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    //call dfs funtion for all nodes
    for(int i = 0;i<V;i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,visited,AdjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}