#include <bits/stdc++.h>

void bfs(int row,int col,vector<vector<int>> &visited,int **arr,int n,int m)
{
   queue<pair<int,int>> q1;
   q1.push({row,col});
   while(!q1.empty())
   {
      int row1 = q1.front().first;
      int col1 = q1.front().second;
      q1.pop();
      visited[row1][col1] = 1;
      for(int i=-1;i<=1;i++)
      {
         for(int j=-1;j<=1;j++)
         {
            int nrow = row1+i;
            int ncol = col1+j;
            if(nrow>=0 && nrow<n && ncol>=0  && ncol<m && arr[nrow][ncol]==1 && visited[nrow][ncol]==0)
            {
               q1.push({nrow,ncol});
            }
         }
      }
   }
}


int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int i;
   int j;
   int count =0;
   vector<vector<int>> visited(n,vector<int>(m,0));
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         if(visited[i][j]==0 && arr[i][j]==1)
         {
            bfs(i,j,visited,arr,n,m);
            count++;
         }
      }
   }

   return count;
}
