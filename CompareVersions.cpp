#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int n = a.length();
    int m = b.length();
    int i=0;
    int j=0;
    while(i<n || j<m)
    {
        long long n1 = 0;
        long long n2 = 0;
        while(i<n && a[i]!='.')
        {
            n1=n1*10 + (a[i]-'0');
            i++;
        }
        while(j<m && b[j]!='.')
        {
            n2=n2*10 + (b[j]-'0');
            j++;
        }
        if(n1>n2)
        return 1;
        else if(n1<n2)
        return -1;
        i++;
        j++;
    }
    return 0;
}