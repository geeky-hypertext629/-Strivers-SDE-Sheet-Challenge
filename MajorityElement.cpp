#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int count = 1;
	int initial = arr[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(arr[i]==initial)
		{
			count++;
		}
		else
		{
			count--;
			if(count==0)
			{
				initial=arr[i];
				count=1;
			}
		}
	}
		int t=0;
		for(i=0;i<n;i++)
		{
			if(arr[i]==initial)
			t++;
		}
		if(t>n/2)
		return initial;
		else
		return -1;
}