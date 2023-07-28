#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your 
  map<long long,int> m;
  int i;
  long long sum=0;
  int res=0;
  for(i=0;i<arr.size();i++)
  {
    sum +=arr[i];
    if(sum==0)
    res=i+1;
    if(m[sum]!=0)
    res = max(res,i-m[sum]);
    else
    m[sum]=i;
  }
  return res;

}