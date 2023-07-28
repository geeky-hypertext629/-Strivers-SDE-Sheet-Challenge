#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	int i;
	int j;
	set<vector<int>> ans;
	int k;
	sort(arr.begin(),arr.end());
	for(i=0;i<n;i++)
	{
		if(i>0 && arr[i]==arr[i-1])
		continue;
		j=i+1;
		k=n-1;
		while(j<k)
		{
			int sum = arr[i] + arr[j] + arr[k];
			if(sum==K)
			{
				ans.insert({arr[i],arr[j],arr[k]});
				j++;
				k--;
			}
			else if(sum<K)
			{
				j++;
			}
			else
			{
				k--;
			}
		}
	}
	vector<vector<int>> temp(ans.begin(),ans.end());
	return temp;
}