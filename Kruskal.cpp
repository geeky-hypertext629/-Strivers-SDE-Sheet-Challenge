#include <bits/stdc++.h> 
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	unordered_map<int,list<pair<int,int>>> adj;
	int i;
	for(i=0;i<m;i++)
	{
		int u = graph[i][0];
		int v = graph[i][1];
		int w = graph[i][2];
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	vector<int> key(n+1);
	vector<int> parent(n+1);
	vector<bool> visited(n+1);

	for(i=0;i<=n;i++)
	{
		key[i] = INT_MAX;
		parent[i] = -1;
		visited[i] = false;
	}

	key[1] = 0; 
	parent[1] = -1; 
	int j;
	for(i=0;i<n-1;i++)
	{
		int mini = INT_MAX;
		int u;
		for(j=1;j<=n;j++)
		{
			if(visited[j]==false && key[j]<mini)
			{
				u = j;
				mini = key[j];
			}
		}

		visited[u]=true;

		for(auto &x:adj[u])
		{
			int v = x.first;
			int w = x.second;
			if(visited[v]==false && w<key[v])
			{
				parent[v] = u;
				key[v] = w;
			}
		}
	}
	int ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=key[i];
	}
	return ans;


}