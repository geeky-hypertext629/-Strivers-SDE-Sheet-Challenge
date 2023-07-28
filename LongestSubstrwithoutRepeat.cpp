#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int i;
    int j=0;
    int maxEnd;
    int n = input.size();
    vector<int> prev(256,-1);
    int res = 0;
    for(i=0;i<n;i++)
    {
        j = max(j,prev[input[i]]+1);
        maxEnd = i-j+1;
        res=max(res,maxEnd);
        prev[input[i]] = i;
    }
    return res;

}