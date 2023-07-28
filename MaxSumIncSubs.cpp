#include <bits/stdc++.h>
  int solve(vector<int> &a, int n,int curr, int prev, vector<vector<int>> &dp){
        // base case
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
            take = a[curr] + solve(a,n, curr+1, curr, dp);
            
        // exclude
        int notTake = 0 + solve(a,n, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);
    }

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    // Write Your Code here
    vector<vector<int>> v(n,vector<int> (n+1,-1));
	return solve(rack,n,0,-1,v);
}
