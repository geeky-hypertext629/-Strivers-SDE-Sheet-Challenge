#include <bits/stdc++.h> 
long long max(long long x,long long y)
{
    if(x>=y)
    return x;
    else
    return y;
}
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    int i;
    long long sum=arr[0];
    long long res=sum;
    for(i=1;i<n;i++)
    {
        sum=max(sum+arr[i],arr[i]);
        res=max(res,sum);
    }
    return max(res,0);
}