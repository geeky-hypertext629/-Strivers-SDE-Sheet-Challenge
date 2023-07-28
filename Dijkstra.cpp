#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<int> dist(vertices,INT_MAX);
    unordered_map<int,list<pair<int,int>>> adjlist;
    int i;
    for(i=0;i<edges;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjlist[v].push_back({u,w});
        adjlist[u].push_back({v,w});
    }
    dist[source] = 0;
    set<pair<int,int>> s1;
    s1.insert({0, source});
    while(s1.size()!=0)
    {
        auto temp = *(s1.begin());
        int node = temp.second;
        int nodeDist = temp.first;
        s1.erase(s1.begin());
        for(auto &pr:adjlist[node])
        {
            if(nodeDist + pr.second<dist[pr.first])
            {
                auto t1 = s1.find(make_pair(dist[pr.first],pr.first));
                if(t1!=s1.end())
                {
                    s1.erase(t1);
                }
                dist[pr.first]=nodeDist + pr.second;
                s1.insert({dist[pr.first], pr.first});
            }
        }
    }


    return dist;

}
