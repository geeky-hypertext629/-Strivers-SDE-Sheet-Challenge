#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    int i;
    vector<int> ans(n,-1);
    stack<int> s1;
    for(i=n-1;i>=0;i--)
    {
        int num = arr[i];
        while(s1.empty()!=true && s1.top()<=num)
        {
            s1.pop();
        }
        if(s1.empty())
        ans[i] = -1;
        else
        ans[i] = s1.top();
        s1.push(num);
    }
    return ans;

}