#include <bits/stdc++.h> 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    int n = v.size();
    int val = 1<<n;
    vector<vector<int>> ans;
    int i;
    for(i=0;i<val;i++)
    {
        vector<int> temp;
        int x = i;
        int pos = 0;
        while(x>0)
        {
            if(x&1)
            temp.push_back(v[pos]);
            pos++;
            x=x/2;
        }
        ans.push_back(temp);
    }
    return ans;
}