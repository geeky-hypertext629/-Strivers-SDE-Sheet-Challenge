#include<bits/stdc++.h>

static int cmd(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int i;
    vector<pair<int,int>> v;
    for(i=0;i<start.size();i++)
    {
        pair<int,int> p;
        p.first = start[i];
        p.second = finish[i];
        v.push_back(p);
    }
    sort(v.begin(),v.end(),cmd);
    int count=1;
    int e = v[0].second;
    for(i=1;i<start.size();i++)
    {
        if(v[i].first>=e)
        {
        count++;
        e=v[i].second;
        }
    }
    return count;
}