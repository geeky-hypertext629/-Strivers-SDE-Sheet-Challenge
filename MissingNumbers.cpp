#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> t(n+1,0);
	int i;
	for(i=0;i<n;i++)
	{
		t[arr[i]]++;
	}
	int missing=0;
	int repeat=0;
	
	for(i=1;i<=n;i++)
	{
		if(t[i]==0)
		missing=i;
		else if(t[i]>1)
		repeat=i;
	}

	pair<int,int> p;
	p=make_pair(missing,repeat);
	return p;


}
