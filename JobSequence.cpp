#include <bits/stdc++.h> 

static bool cmd(vector<int> v1,vector<int> v2)
{
    return v1[1]>v2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),cmd);
    int i;
    int n = jobs.size();
    int maxi = 0;
    for(i=0;i<n;i++)
    {
        maxi = max(maxi,jobs[i][0]);
    }
    vector<int> v(maxi,0);
    int count = 0;
    for(i=0;i<n;i++)
    {
        int nums = jobs[i][0];
        while(nums-1>=0)
        {
            if(v[nums-1]==0)
            {
                v[nums-1]=1;
                count+=jobs[i][1];
                break;
            }
            nums--;
        }
    }
    return count;
}
