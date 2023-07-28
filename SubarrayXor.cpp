#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int i;
    int j;
    int xor1=0;
    int count=0;
    int n=arr.size();
    for(i=0;i<n;i++)
    {
        xor1=arr[i];
        if(xor1==x)
        count++;
        for(j=i+1;j<n;j++)
        {
            xor1^=arr[j];
            if(xor1==x)
            count++;
        }
    }
    return count;
}