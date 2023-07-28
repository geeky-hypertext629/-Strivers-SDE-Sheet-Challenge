#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int p1 = p.length();
    int s1 = s.length();
    int i;
    for(i=0;i<s1;i++)
    {
        if((i+p1-1)<s1)
        {
            if(s.substr(i,p1)==p)
            {
                return true;
            }
        }
    }
    return false;
}