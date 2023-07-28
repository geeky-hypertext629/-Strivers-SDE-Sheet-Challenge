#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long> lmax(n);
    vector<long> rmax(n);
    lmax[0] = arr[0];
    rmax[n-1] = arr[n-1];
    int i;
    for(i=1;i<n;i++)
    {
        lmax[i] = max(lmax[i-1],arr[i]);
    }
    for(i=n-2;i>=0;i--)
    {
        rmax[i] = max(rmax[i+1],arr[i]);
    }
    long ans = 0;
    for(i=1;i<n-1;i++)
    {
        ans+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return ans;
}