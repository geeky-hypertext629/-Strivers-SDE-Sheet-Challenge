#include <bits/stdc++.h> 

static bool cmd(pair<int, int> v1,pair<int, int> v2)
{
    return (((v1.second*1.0)/v1.first) > ((v2.second*1.0)/v2.first));
}
double maximumValue(vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    // vector<vector<double>> v1;
    int i;
    // for(i=0;i<n;i++)
    // {
    //     double ratio = ((items[i].second*1.0)/items[i].first);
    //     v1.push_back({items[i].first,items[i].second,ratio});
    // }
    sort(items.begin(),items.end(),cmd);
    double ans = 0.0;
    for(i=0;i<n;i++)
    {
        if(items[i].first<=w)
        {
            ans+=items[i].second;
            w=w-items[i].first;
        }
        else
        {
            ans += ((w*1.0)/items[i].first)*items[i].second;
            break;
        }
    }
    return ans;

}