#include <bits/stdc++.h>


vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   sort(arr.begin(),arr.end());
   vector<vector<int>> ans;
   int i=0;
   int j=0;
   int n=arr.size();
   for(i=0;i<n-1;i++)
   {
      for(j=i+1;j<n;j++)
      {
         if(arr[i]+arr[j]==s)
         {
            vector<int> t(2,0);
            t[0]=arr[i];
            t[1] = arr[j];
            ans.push_back(t);
         }
      }
   }
   sort(ans.begin(),ans.end());
   return ans;
}