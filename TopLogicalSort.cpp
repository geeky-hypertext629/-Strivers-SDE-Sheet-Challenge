#include <bits/stdc++.h> 

void dfs(unordered_map<int,vector<int>> &adj,vector<int> &visited,int n,int start,stack<int> &s1)
{
    visited[start] = 1;
    for(auto &pr:adj[start])
    {
        if(visited[pr]==0)
            dfs(adj,visited,n,pr,s1);
    }
    s1.push(start);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int,vector<int>> m;
    // int n = edges.size();
    int i;
    for(i=0;i<e;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        m[u].push_back(v);
    }
    vector<int> visited(v,0);
    stack<int> s1;
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            dfs(m,visited,v,i,s1);
        }
    }
    vector<int> ans;
    while(!s1.empty())
    {
        ans.push_back(s1.top());
        s1.pop();
    }
    return ans;
}