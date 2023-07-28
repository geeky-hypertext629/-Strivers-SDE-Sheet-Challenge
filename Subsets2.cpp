#include <bits/stdc++.h> 
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    int i;
    set<vector<int>> ans;
    int num = 1<<n;
    for(i=0;i<num;i++)
    {
        int x = i;
        int pos=0;
        vector<int> temp;
        while(x>0)
        {
            if(x&1)
            {
                temp.push_back(arr[pos]);
            }
            x=x/2;
            pos++;
        }
        sort(temp.begin(),temp.end());
        ans.insert(temp);
    }
    vector<vector<int>> ansFinal(ans.begin(),ans.end());
    return ansFinal;
}