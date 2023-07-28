#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.	
	if(n==1)
	return "1";
	else if(n==2)
	return "11";
	string s="11";
	int i;
	int j;
	for(i=3;i<=n;i++)
	{
		string t="";
		s=s+'&';
		int c=1;
		for(j=1;j<s.length();j++)
		{
			if(s[j]!=s[j-1])
			{
				t+=to_string(c);
				t+=s[j-1];
				c=1;
			}
			else
			c++;
		}
		s=t;
	}
	return s;
}