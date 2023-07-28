#include<bits/stdc++.h>

bool isPalin(string s2,int i,int j)
{
  while(i<j)
  {
    if(s2[i]!=s2[j])
    return false;
    i++;
    j--;
  }
  return true;
}

int solve(string s1,int start,int n,vector<int> &dp)
{
  if(start==n)
  {
    return 0;
  }
  if(dp[start]!=-1)
  return dp[start];
  int minCost = INT_MAX;
  int j;
  for(j=start;j<n;j++)
  {
    if (isPalin(s1, start, j)==true) {
      int cost = 1 + solve(s1, j + 1, n,dp);
      minCost = min(minCost, cost);
    }
  }
  return dp[start]=minCost;
}


int palindromePartitioning(string str)
{
    // Write your code here
    int ind = 0;
    int n = str.size();
    vector<int> dp(n,-1);
    return solve(str,ind,n,dp)-1;
}
