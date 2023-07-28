#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	if(n==0)
	return {arr[0]};
	if(n==1)
	return {arr[0],(arr[0]+arr[1])/2};
	vector<int> ans;
	ans.push_back(arr[0]);
	ans.push_back((arr[0]+arr[1])/2);
	int i;
	priority_queue<int> pq1;
	priority_queue<int,vector<int>,greater<int>> pq2;
	pq1.push(min(arr[0],arr[1]));
	pq2.push(max(arr[0],arr[1]));
	int s1 = 1;
	int s2 = 1;
	for(i=2;i<n;i++)
	{
		if(arr[i]<pq2.top())
		{
			s1++;
			pq1.push(arr[i]);
		}
		else
		{
			s2++;
			pq2.push(arr[i]);
		}
		if(abs(pq1.size()-pq2.size())>=2)
		{
			if(s1>s2)
			{
				s1--;
				s2++;
				pq2.push(pq1.top());
				pq1.pop();
			}
			else{
				s1++;
				s2--;
				pq1.push(pq2.top());
				pq2.pop();
			}
		}
				if (s1==s2) ans.push_back((pq2.top()+pq1.top())/2);
		else if (s1>s2) ans.push_back(pq1.top());
		else ans.push_back(pq2.top());
	}
	return ans;
}
