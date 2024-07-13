#include<unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<limits.h>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //Create ajacency List
    unordered_map<int,list<pair<int,int>>> adjList;
    for(int i = 0 ; i < edges ; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back(make_pair(u,w));
    }

    vector<int> dist(vertices);
    for(int i = 0;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    set<pair<int,int>> s;

    s.insert(make_pair(0,source));

    while(!s.empty())
    {
        //fetch top record
        auto top = *(s.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //erase top record now
        s.erase(s.begin());

        //traverse on neigbours
        for(auto i : adjList[topNode])
        {
            if(nodeDistance + i.second < dist[i.first])
            {
                auto record = s.find(make_pair(dist[i.first],i.first));
                //if record found delete erase it
                if(record != s.end())
                {
                    s.erase(record);
                }

                //distance update
                dist[i.first] = nodeDistance + i.second;
                //insert updated 
                s.insert(make_pair(dist[i.first],i.first));
            }
        }
    }
    return dist;
}
