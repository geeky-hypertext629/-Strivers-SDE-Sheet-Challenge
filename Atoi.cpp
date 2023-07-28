#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int count=0;
    int i;
    for(i=0;i<str.size();i++)
    {
        if(str[i]-'0'>=0 && str[i]-'0'<=9)
        {
            count = count*10 + (str[i]-'0');
        }
    }
    if(str[0]=='-')
    count = 0 - count;
    return count;
}