#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n,int m,vector<pair<pair<int,int>,int>> &g)
{
    // Write your code here.
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);
    vector<int> dist(n+1,INT_MAX);

    int i;
    int j;
    unordered_map<int,vector<pair<int,int>>> adj;
    for(i=0;i<m;i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dist[1]=0;
    // vis[0] = true;
    for(i=1;i<=n;i++)
    {
        int mini = INT_MAX;
        int u;
        for(j=1;j<=n;j++)
        {
            if(vis[j]==false && dist[j]<mini)
            {
                u = j;
                mini = dist[j];
            }
        }

        vis[u] = true;

        for(auto &pr:adj[u])
        {
            int v= pr.first;
            int wt= pr.second;
            if(vis[v]==false && wt<dist[v])
            {
                parent[v]=u;
                dist[v] = wt;
            }
        }

    }
       vector<pair<pair<int, int>, int>> result;
       for(int i =2;i<=n;i++)
         {
           result.push_back({{parent[i],i},dist[i]});
           }
      return result; 
}
