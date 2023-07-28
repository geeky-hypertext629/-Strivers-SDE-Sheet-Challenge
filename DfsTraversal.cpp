void dfs(unordered_map<int,list<int>> &adjlist,unordered_map<int,bool> &visited,vector<int> &component,int node)
{
    component.push_back(node);
    visited[node]=true;

    for(auto x : adjlist[node])
    {
        if(visited[x]==false)
        {
             dfs(adjlist,visited,component,x);
        }
    }
}



vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adjlist;
    int i;
    for(i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int,bool> visited;

    vector<vector<int>> ans;

    for(i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            vector<int> component;
            dfs(adjlist,visited,component,i);
            ans.push_back(component);
        }
    }
    return ans;

}