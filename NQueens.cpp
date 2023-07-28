#include <bits/stdc++.h>

void add(vector<vector<int>> &board,vector<vector<int>> &ans,int n)

{

    vector<int> temp;

 

    for(int i=0; i<n; i++)

  {

        for(int j=0; j<n; j++)

      {

            temp.push_back(board[i][j]);

        }

    }

    ans.push_back(temp);

}
int isSafe(vector<vector<int>> &board,int row,int col,int n)
{
    int i=row;
    int j=col;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
        return false;
        i--;
        j--;
    }
    i=row;
    j=col;
    while(j>=0)
    {
        if(board[i][j]==1)
        return false;
        j--;
    }
    j=col;
    while(i<n && j>=0)
    {
        if(board[i][j]==1)
        return false;
        i++;
        j--;
    }
    return true;
}

void solve(vector<vector<int>> &board,int col,vector<vector<int>> &ans,int n)
{
    if(col>=n)
    {
         add(board,ans,n);

        return ;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col,n))
            {
                board[i][col]=1;
                solve(board,col+1,ans,n);
                board[i][col]=0;
            }
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n,vector<int>(n,0));
    int i;
    vector<vector<int>> ans;
    solve(board,0,ans,n);
    return ans;
}