#include <bits/stdc++.h> 

void constAdj(unordered_map<int,set<int>> &m1,vector<pair<int, int>> edges)
{
    int i;
    int n = edges.size();
    for(i=0;i<n;i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;

        m1[u].insert(v);
        m1[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adj,unordered_map<int,int> &visited,vector<int> &ans,int node)
{
    queue<int> q1;
    q1.push(node);
    visited[node]=1;

    while(!q1.empty())
    {
        int top1 = q1.front();
        q1.pop();
        ans.push_back(top1);
        for(auto &pr:adj[top1])
        {
            if(visited[pr]==0)
            {
                q1.push(pr);
                visited[pr]=true;
            }
        }
    }


}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int,set<int>> m1;
    unordered_map<int,int> visited;
    vector<int> ans;
    constAdj(m1,edges);
    int i;
    for(i=0;i<vertex;i++)
    {
        if(visited[i]==0)
        {
            bfs(m1,visited,ans,i);
        }
    }
    return ans;
    
}