#include <unordered_map>
#include <stack>
#include <list>
#include<vector>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,stack<int> &st,
			unordered_map<int,list<int>> &adj)
	{
		visited[node] = true;
		for(auto nbr : adj[node])
		{
			if(!visited[nbr])
			{
				dfs(nbr, visited, st, adj);
			}
		}
		st.push(node); // topo logic
	}

void revDfs(int node,unordered_map<int,bool> &visited,
			unordered_map<int,list<int>> &adj)
{
	visited[node] = true;
	for(auto nbr : adj[node])
	{
		if(!visited[nbr])
		{
			revDfs(nbr, visited, adj);
		}
	}
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//create adj
	unordered_map<int,list<int>> adj;
	for(int i = 0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int n = edges[i][1];

		adj[u].push_back(n);
	}

	//topo sort
	stack<int> st;
	unordered_map<int,bool> visited;
	for(int i = 0;i<v;i++)
	{
		if(!visited[i])
		{
			dfs(i,visited,st,adj);
		}
	}

	//create a transpose of a graph
	unordered_map<int,list<int>> transpose;
	for(int i = 0;i<v;i++)
	{
		visited[i] = 0;
		for(auto nbr : adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	//DFS for tanspose ordering
	int count = 0;
	while(!st.empty())
	{
		int top =  st.top();
		st.pop();
		if(!visited[top])
		{
			count++;
			revDfs(top, visited, transpose);
		}
	}
	return count;
}