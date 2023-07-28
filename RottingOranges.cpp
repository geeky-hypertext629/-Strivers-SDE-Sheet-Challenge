#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    vector<vector<int>> vis(n,vector<int>(m,0));
    int i;
    int j;
    queue<pair<pair<int,int>,int>> q1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q1.push({{i,j},0});
                vis[i][j]=2;
            }
        }
    }
    int tm = 0;
    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};
    while(!q1.empty())
    {
        int row1 = q1.front().first.first;
        int col1 = q1.front().first.second;
        int t = q1.front().second;
         tm = max(tm,t);
        q1.pop();
         for(i=0;i<4;i++)
         {
             int row= row1 + delRow[i];
             int col=col1 + delCol[i];
             if(col>=0 && row>=0 && row<n && col<m && vis[row][col]!=2 && grid[row][col]==1)
             {
                 q1.push({{row,col},t+1});
                 vis[row][col] = 2;
             }
         }
    }
        for(int i=0; i<n; i++){

        for(int j=0; j<m; j++){

            if(vis[i][j]!=2 && grid[i][j]==1)return -1;

        }

    }
    return tm;

}