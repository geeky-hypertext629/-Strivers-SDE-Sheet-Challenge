#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long ans = 1;
	while(n>0)
	{
		if(n&1)
		{
			ans = ans*x%m;
			n--;
		}
		else
		{
			x=x*1LL*x%m;
			n=n/2;
		}
	}
	return ans;

}