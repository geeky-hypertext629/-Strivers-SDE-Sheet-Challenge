#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &a, int n) {
    // Write your code here.
    set<int> s1(a.begin(),a.end());
    int count = 1;
    int pre=INT_MIN;
    int res = 1;
    int i;
    for(auto &pr:s1)
    {
        if(pre+1==pr)
        count++;
        else
        count=1;
        pre=pr;
        res=max(res,count);
    }
    return res;
}   