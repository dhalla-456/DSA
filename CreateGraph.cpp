#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

//template <typename T>

class graph{

    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction)
    {
        //direction = 0 -> undirected graph
        //direction = 1 -> directed graph

        //creating edges from u to v
        adj[u].push_back(v);
        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n,m;
    cout<<"Enter the number of nodes : ";
    cin>>n;
    cout<<"Enter the number of edges : ";
    cin>>m;

    graph g;

    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating undirected graph
        g.addEdge(u,v,0);
    }

    //print Graph
    g.printAdjList();
}



//Adj matrix
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout<<"Enter the number of nodes in graph"<<endl;
//     cin >> n;
//     int m;
//     cout<<"Enter the number of edges in graph"<<endl;
//     cin >> m;
//     vector<vector<int>> adj(n+1,vector<int>(n+1,0));
//     for(int i=0;i<m;i++)
//     {
//         int u,v;
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }
    
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(adj[i][j])
//             {
//                 cout<<i<<"->"<<j<<endl;
//             }
//         }
//     }
    
    

//     return 0;
// }



//Creating and Printing Code Studio

// #include <bits/stdc++.h> 
// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     vector<vector<int>> ans(n);
//     //vector<int> ans[n];//chiye aise likh lo ya upr ke jaise
      //ans will store all ajacent nodes corresponding to indexes
//     for(int i=0;i<m;i++){
//         int u=edges[i][0];
//         int v=edges[i][1];

//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }
//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++){
//         adj[i].push_back(i);
           //entering neighbours
//         for(int j=0;j<ans[i].size();j++){
//             adj[i].push_back(ans[i][j]);
//         }
//     }
//     return adj;
// }
