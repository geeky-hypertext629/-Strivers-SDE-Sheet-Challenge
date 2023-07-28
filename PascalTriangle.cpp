#include <bits/stdc++.h>

vector<long long> generateRow(int i)
{
  long long ans = 1;
  vector<long long> res;
  res.push_back(ans);
  for(int j=1;j<i;j++)
  {
      ans = ans*(i-j);
      ans = ans/j;
      res.push_back(ans);
  }
  return res;
}

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  int r= 1;
  vector<vector<long long>> ans;
  for(int i=1;i<=n;i++)
  {
    ans.push_back(generateRow(i));
  }
  return ans;
}
