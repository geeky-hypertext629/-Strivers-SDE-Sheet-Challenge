#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    int i;
    for(i=0;i<n;i++)
    {
        if(q[i][0]==1)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        else
        {
            pq.push(q[i][1]);
        }
    }
    return ans;
}
