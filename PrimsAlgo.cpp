//Code using Priority queue :  
#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<limits.h>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
 vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

		// min heap to get node with minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	  // let source as 1, and inititally distance of source is 0
		// {weight, node}  
		pq.push({0, 1});

    vector<int> key(n+1, INT_MAX), parent(n+1, -1), visited(n+1, 0);

    parent[1] = -1;
		// weight to reach i is key[i]
    key[1] = 0;

    while(pq.size()) {
        int w = pq.top().first;
        int node = pq.top().second;
        visited[node] = 1;
        pq.pop();

				// find node with minimum weight and to to its neighbour 
        for(auto neg: adj[node]) {
            int toGo = neg.first;
            int toGoWeg = neg.second;

						// if to react node N from key[N] update weight(key[N]) with distance from node to N
            if(visited[toGo] == 0 && toGoWeg < key[toGo]) {
                key[toGo] = toGoWeg;
                parent[toGo] = node;
                pq.push({toGoWeg, toGo});
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;
	   // loop from 2 because parent of 1 is -1 (1 is initial node)
		for(int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, key[i]});

    }
    
    return ans;
}


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(auto i : g) {
        int u = i.first.first;
        int v = i.first.second;
        int w = i.second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> mst(n+1, 0);

    parent[1] = -1;
		// weight to reach i is key[i]
    key[1] = 0;

    for (int i = 1; i < n; i++)
    {
      int mini = INT_MAX;
      int u;
      //find the min wali node
      for (int v = 1; v <= n; v++)
      {
        if(mst[v] == false && key[v] < mini)
        {
          u = v;
          mini = key[v];
        }
      }
      
      //mark min node as true
      mst[u] = true;

      //check its adjacent nodes
      for(auto it:adj[u])
      {
        int v = it.first;
        int w = it.second;
        if(mst[v] == false && w < key[v])
        {
          parent[v] = u;
          key[v] = w;
        }
      }
    }
    
    vector<pair<pair<int,int>,int>> result;
    for (int i = 2; i <= n; i++)
    {
      result.push_back({{parent[i],i},key[i]});
    }

    return result;

}