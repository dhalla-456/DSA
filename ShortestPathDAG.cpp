#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<limits.h>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

class Graph
{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;
    
    void AddEdges(int u ,int v, int weight)
    {
        pair<int,int> p = make_pair(v,weight);
        adjList[u].push_back(p);
    }

    void printAdj()
    {
        for(auto i : adjList)
        {
            cout<<i.first <<"->";
            for(auto j : i.second)
            {
                cout<< "(" << j.first << "," << j.second << ")," ;
            }cout<<endl;
        }
    }

    void DFS(int node,unordered_map<int,bool> &visited,stack<int> &s)
    {
        visited[node] = 1;
        for(auto i : adjList[node])
        {
            if(visited[i.first])
            {
                DFS(i.first,visited,s);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src,vector<int> &dist,stack<int> &s)
    {
        dist[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX)
            {
                for(auto i : adjList[top])
                {
                    if(dist[top] + i.second < dist[i.first])
                    {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
        
    }

};

int main()
{
    Graph g;
    g.AddEdges(0,1,5);
    g.AddEdges(0,2,3);
    g.AddEdges(1,2,2);
    g.AddEdges(1,3,6);
    g.AddEdges(2,3,7);
    g.AddEdges(2,4,4);
    g.AddEdges(2,5,2);
    g.AddEdges(3,4,-1);
    g.AddEdges(4,5,-2);

    g.printAdj();

    int n = 6;

    //Topological Sort
    unordered_map<int,bool> visited;
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.DFS(i,visited,s);
        }
    }
    
    int src = 1;
    vector<int> dist(n);

    for(int i = 0; i < n ; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    g.getShortestPath(src,dist,s);

    cout<<"Answer is : "<<endl;

    for(int i = 0; i < dist.size() ; i++)
    {
        cout<<dist[i] << ",";
    }cout<<endl;

    return 0;
}