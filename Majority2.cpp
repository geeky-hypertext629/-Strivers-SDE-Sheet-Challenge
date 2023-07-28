#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    map<int,int> m;
    int n=arr.size();
    for(auto &pr:arr)
    {
        if(m[pr]!=-1)
        m[pr]++;
        if(m[pr]>n/3)
        {
            ans.push_back(pr);
            m[pr]=-1;
        }
    }
    return ans;

}