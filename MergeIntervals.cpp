#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
static int cmd(vector<int> v1,vector<int> v2)
{
    return v1[0]<v2[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end(),cmd);
    vector<vector<int>> ans;
    int i;
    int n=intervals.size();
    int res=0;
    vector<int> temp;
    temp.push_back(intervals[0][0]);
    temp.push_back(intervals[0][1]);
    ans.push_back(temp);
    for(i=1;i<n;i++)
    {
        if(ans[res][1]>=intervals[i][0])
        {
            ans[res][0]=min(ans[res][0],intervals[i][0]);
            ans[res][1]=max(ans[res][1],intervals[i][1]);
        }
        else
        {
            res++;
            vector<int> t(2);
            t[0]=intervals[i][0];
            t[1]=intervals[i][1];
            ans.push_back(t);
        }
    }
    return ans;
}
