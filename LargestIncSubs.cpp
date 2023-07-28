#include <bits/stdc++.h>
  int solve(int a[], int n,int curr, int prev, vector<vector<int>> &dp){
        // base case
        if(curr == n){
            return 0;
        }
        
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
        
        // include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solve(a,n, curr+1, curr, dp);
            
        // exclude
        int notTake = 0 + solve(a,n, curr+1, prev, dp);
        
        return dp[curr][prev+1] = max(take, notTake);
    }

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int>temp;

temp.push_back(arr[0]);

int len=1;

for(int i=1;i<n;i++)

{

if(arr[i]>temp.back())

{

temp.push_back(arr[i]);

len++;

}

else

{

int ind=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();

temp[ind]=arr[i];

}

 

 

}

return len;
}
