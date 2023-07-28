#include <bits/stdc++.h> 


int isSafe(int x,int y,vector<vector<bool>> &visited,vector<vector<int> > &maze,int n)
{
  if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==false && maze[x][y]==1)
  return true;
  return false;
}


void solve(int x,int y,string path,vector<vector<int> > &ans,vector<vector<bool>> &visited,vector<vector<int>> &maze,int n)
{
  if(x==n-1 && y==n-1)
  {
        vector<int> temp;

    visited[x][x]=1;

    for(int k=0;k<n;k++)

    {

      for (int l = 0; l < n; l++)

      {

        temp.push_back(visited[k][l]);
      }
    }

    visited[x][y]=0;

    ans.push_back(temp);

    return;
  }

  visited[x][y]=true;

  if(isSafe(x+1,y,visited,maze,n))
  {
    solve(x+1,y,path+"D", ans, visited,maze,n);
  }

  if(isSafe(x,y-1,visited,maze,n))
  {
    solve(x,y-1,path+"L", ans, visited,maze,n);
  }
  if(isSafe(x,y+1,visited,maze,n))
  {
    solve(x,y+1,path+"R", ans, visited,maze,n);
  }
  if(isSafe(x-1,y,visited,maze,n))
  {
    solve(x-1,y,path+"U", ans, visited,maze,n);
  }

  visited[x][y]=false;

}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<bool>> temp(n,vector<bool> (n,0));
  vector<vector<int> > ans;
  if(maze[0][0]==0)
  {
    return ans;
  }
  string path="";
  solve(0,0,path,ans,temp,maze,n);
  return ans;
}