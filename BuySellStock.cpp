#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int ans=prices[1] - prices[0];
    int minEle=prices[0];
    int i;
    int n=prices.size();
    for(i=1;i<n;i++)
    {
        ans=max(ans,prices[i]-minEle);
        minEle=min(minEle,prices[i]);
    }
    if(ans<0)
    return 0;
    return ans;
}