#include <bits/stdc++.h>

// int solve(string str1,string str2,int n,int m,vector<vector<int>> &t)
// {
// 	if(n==0 || m==0)
// 	return 0;
// 	if(t[n][m]!=-1)
// 	return t[n][m];
// 	else if (str1[n-1]==str2[m-1])
// 	{
// 		return t[n][m] = 1 + solve(str1,str2,n-1,m-1,t);
// 	}
// 	else
// 	{
// 		return t[n][m] = max(solve(str1,str2,n-1,m,t),solve(str1,str2,n,m-1,t));
// 	}
// }

int minCharsforPalindrome(string str) {
	// Write your code here.
	// int n = str.length();
	// vector<vector<int>> v(n+1,vector<int>(n+1,-1));
	// string rev = str;
	// reverse(rev.begin(),rev.end());
	// return n - solve(str,rev,n,n,v);

	int res = 0;
	int i=0;
	int j = str.length()-1;
	int trim = j;
	while(i<j)
	{
		if(str[i]==str[j])
		{
			i++;
			j--;
		}
		else
		{
			res++;
			i=0;
			j=--trim;
		}
	}
	return res;
}
