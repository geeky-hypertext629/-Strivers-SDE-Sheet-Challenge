#include<bits/stdc++.h>

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	int i;
	int count=0;
	for(i=0;i<n-m+1;i++)
	{
		if(s[i]==p[0])
		{
			if(s.substr(i,m)==p)
			count++;
		}
	}
	return count;
}