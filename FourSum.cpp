#include <bits/stdc++.h>

bool isPossible(vector<int> arr,int index,int target)
{
    int l= arr.size()-1;
    while(index<=l)
    {
        if(arr[index]+arr[l]==target)
        return true;
        else if(arr[index]+arr[l]<target)
        index++;
        else
        l--;
    }
    return false;
}

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here 
    int i;
    int j;
    sort(arr.begin(),arr.end());
    for(i=0;i<n-3;i++)
    {
        for(j=i+1;j<n-2;j++)
        {
            if(isPossible(arr,j+1,target-arr[i]-arr[j]))
            return "Yes";
        }
    }
    return "No";
}
