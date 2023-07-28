#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    // int n = kArrays.size();
    int m = kArrays[0].size();
    vector<int> ans;
    int i;
    int j;
    for(i=0;i<k;i++)
    {
        m=kArrays[i].size();
        for(j=0;j<m;j++)
        {
            ans.push_back(kArrays[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
