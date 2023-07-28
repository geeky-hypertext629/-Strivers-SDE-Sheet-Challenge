#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	vector<bool> v(n,false);
	int i;
	for(i=0;i<n;i++)
	{
		if(v[arr[i]]==true)
		return arr[i];
		else
		v[arr[i]]=true;
	}
	return -1;
}
