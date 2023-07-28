 #include<bits/stdc++.h>
 
 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   stack<int> s1;
   stack<int> s2;
   int n = heights.size();
   vector<int> prevSmall(n,-1);
   vector<int> nextSmall(n,-1);
   int i;
   for(i=0;i<n;i++)
   {
     while(s1.empty()==false && heights[s1.top()]>=heights[i])
     {
       s1.pop();
     }
     if(s1.empty())
     prevSmall[i] = 0;
     else
     prevSmall[i] = s1.top()+1;
     s1.push(i);
   }
   for(i=n-1;i>=0;i--)
   {
     while(s2.empty()==false && heights[s2.top()]>=heights[i])
     {
       s2.pop();
     }
     if(s2.empty())
     nextSmall[i] = n-1;
     else
     nextSmall[i] = s2.top()-1;
     s2.push(i);
   }

   int res = 0;
   for(i=0;i<n;i++)
   {
     int curr = heights[i]*(nextSmall[i]-prevSmall[i]+1);
     res = max(res,curr);
   }
   return res;


 }