#include <bits/stdc++.h> 

void solve(vector<string> &temp,string s,int index)
{
    if(index>=s.length())
    {
        temp.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++)
    {
        swap(s[i],s[index]);
        solve(temp,s,index+1);
        swap(s[i],s[index]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    solve(ans,s,0);
    return ans;
}