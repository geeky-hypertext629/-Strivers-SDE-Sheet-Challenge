#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> v(n+1);
    map<int,int> m;
    int i;
    for(i=0;i<=n;i++)
    {
        vector<int> t;
        v.push_back(t);
    }
    for(i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    for(auto &pr:m)
    {
        v[pr.second].push_back(pr.first);
    }
    vector<int> ans;
    int t=0;
    for(i=n;i>=0;i--)
    {
        for(int j=0;j<v[i].size();j++)
        {
            if(t==k)
            break;
            ans.push_back(v[i][j]);
            t++;
        }
        if(t==k)
        break;
    }
    sort(ans.begin(),ans.end());
    return ans;
}