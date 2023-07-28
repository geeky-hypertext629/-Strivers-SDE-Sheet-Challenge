#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> t(n + 1, vector<bool>(k + 1, false));
    int i;
    int j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(i==0)
            {
                t[i][j]=false;
            }
            if(j==0)
            {
                t[i][j]=true;
            }
        }
    }
    //   if(arr[n-1]<=k){

    //     t[n][k]=t[n-1][k-arr[n-1]] || t[n-1][k];

    // }else{

    //     t[n][k]=t[n-1][k];

    // }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j] =t[i-1][j-arr[i-1]] || t[i-1][j]; 
            }
            else
            {
                t[i][j] =t[i-1][j];
            }
        }
    }
    return t[n][k];
}