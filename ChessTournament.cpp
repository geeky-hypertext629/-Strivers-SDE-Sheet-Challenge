#include <bits/stdc++.h> 

int isPossible(int mid,vector<int> &pos,int c,int n)
{
	int i;
	int count=1;
	int prev= pos[0];
	for(i=1;i<n;i++)
	{
		if(pos[i]-prev>=mid)
		{
			count++;
			prev = pos[i];
		}
	}
	if(count>=c)
	{
		return true;
	}
	else
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int l= 1;
	int h = positions[n-1];
	int res= -1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(isPossible(mid,positions,c,n))
		{
			res = mid;
			l=mid+1;	
		}
		else{
			h=mid-1;
		}
	}
	return res;
}