#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1,1e9);
    dist[src] = 0;
    int i;
    int j;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<edges.size();j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u]!=1e9 && ((dist[u] + wt)<dist[v]))
            {
                dist[v]=dist[u] + wt;
            }
        }
    }

    return dist[dest];
}