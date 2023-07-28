#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int prefix = 1;
	int suffix = 1;
	int ans = INT_MIN;
	int i;
	for(i=0;i<n;i++)
	{
		suffix = suffix*arr[i];
		prefix = prefix*arr[n-i-1];
		ans = max(ans,max(prefix,suffix));
		if(suffix==0)
		suffix=1;
		if(prefix==0)
		prefix=1;
	}
	return ans;
}
