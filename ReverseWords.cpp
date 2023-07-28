#include <bits/stdc++.h>

string reverseString(string &str){
	// Write your code here.
	stack<string> s1;
	int i;
	string temp="";
	string ans="";
	int k=0;
	int j=str.size()-1;
	for(i=0;i<str.size();i++)
	{
		if(str[i]!=' ')
		break;
	}
	for(j=str.size()-1;j>=0;j--)
	{
		if(str[j]!=' ')
		break;
	}
	for(i=i;i<=j;i++)
	{
		if(str[i]!=' ')
		{
			temp.push_back(str[i]);
		}
		else
		{
			if(i-1>=0)
			{
                          if (str[i - 1] !=' ') {
                            s1.push(temp);
                            temp = "";
                          }
            }
        }
        }
		s1.push(temp);
		while(!s1.empty())
		{
			ans +=s1.top();
			s1.pop();
			if(s1.size()!=0)
			ans.push_back(' ');
		}
		return ans;

}