#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k) {
  //    Write your code here.
  int i;
  int j;
  vector<int> ans;
    deque<int> pq;
    for(i=0;i<k;i++)
    {
      while(!pq.empty() && nums[pq.back()]<=nums[i])
      pq.pop_back();

      pq.push_back(i);

    }
    for(i=k;i<nums.size();i++)
    {
      ans.push_back(nums[pq.front()]);
      while(!pq.empty() && pq.front()<=i-k)
      pq.pop_front();
      while(!pq.empty() && nums[pq.back()]<=nums[i])
      pq.pop_back();
      pq.push_back(i);
    }
    ans.push_back(nums[pq.front()]);
  return ans;
}