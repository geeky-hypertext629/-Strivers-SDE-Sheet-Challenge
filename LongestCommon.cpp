#include <bits/stdc++.h>
int solve(string s, string s2,int n,int m,vector<vector<int>> &t)
{
	if(n<=0 || m<=0)
	return 0;
	if(t[n][m]!=-1)
	return t[n][m];
	if(s[n-1]==s2[m-1])
	{
		return t[n][m]= 1 + solve(s,s2,n-1,m-1,t);
	}
	else
	{
		return t[n][m] = max(solve(s,s2,n-1,m,t),solve(s,s2,n,m-1,t));
	}
}



int lcs(string s1, string s2)
{
	//Write your code here
	int n = s1.length();
	int m = s2.length();
	vector<vector<int>> t(n+1,vector<int>(m+1,-1));
	return solve(s1,s2,n,m,t);
}