#include <bits/stdc++.h>
bool solve(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,int node)
{
    queue<pair<int,int>> q1;
    q1.push({node,-1});
    visited[node]=true;

    while(!q1.empty())
    {
        int node1 = q1.front().first;
        int parent = q1.front().second;
        q1.pop();

        for(auto &pr:adjlist[node1])
        {
            if(!visited[pr])
            {
                q1.push({pr,node1});
                visited[pr]=true;
            }
            else if(pr!=parent)
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adjlist;
    int i;
    for(i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    unordered_map<int,bool> visited;

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans = solve(adjlist,visited,i);
            if(ans==true)
            return "Yes";
        }
    }
    return "No";
    
}
