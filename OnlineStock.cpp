#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>> s1;
    int i;
    vector<int> ans;
    for(i=0;i<price.size();i++)
    {
        int days=1;
        while(!s1.empty() && (s1.top().first)<=price[i])
        {
            days+=s1.top().second;
            s1.pop();
        }
        s1.push({price[i],days});
        ans.push_back(days);
    }
    return ans;
}