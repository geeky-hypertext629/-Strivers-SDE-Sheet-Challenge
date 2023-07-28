#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    map<int,int> m;
    int i;
    vector<int> ans;
    for(i=0;i<k;i++)
    {
        m[arr[i]]++;
    }
    ans.push_back(m.size());
    for(i=k;i<arr.size();i++)
    {
        if(m[arr[i-k]]!=0)
        {
            m[arr[i-k]]--;
            if(m[arr[i-k]]==0)
            m.erase(arr[i-k]);
        }
        m[arr[i]]++;
        
        ans.push_back(m.size());
    }
    return ans;


	
}
