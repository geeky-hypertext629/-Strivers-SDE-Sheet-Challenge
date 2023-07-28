#include <bits/stdc++.h> 

bool isPossible(vector<int> time,int n,int m,long long mid)
{
	int stud = 0;
	long long pages = 0 ;
	int i;
	for(i=0;i<m;i++)
	{
		if(pages+time[i]<=mid)
		{
			pages+=time[i];
		}
		else
		{
			pages = time[i];
			stud++;
		}
	}
	if(stud<n)
	return true;
	else
	return false;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long sum = 0;
	int i;
	long long mini = INT_MIN;
	for(auto x:time)
	{
		sum +=x;
		if(x>mini)
		{
			mini =x;
		}
	}
	long long ans = 0;
	while(mini<=sum)
	{
		long long mid = (mini + sum)/2;
		if(isPossible(time,n,m,mid))
		{
			ans = mid;
			sum = mid-1;
		}
		else
		{
			mini = mid+1;
		}
	}
	return ans;

}