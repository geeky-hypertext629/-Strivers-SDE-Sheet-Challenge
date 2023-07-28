#include <bits/stdc++.h> 
int maximumXor(vector<int> A)
{
    // Write your code here.  
    int maxi = 0;
    int i;
    int j;
    for(i=0;i<A.size()-1;i++)
    {
        for(j=i+1;j<A.size();j++)
        {
            if((A[i]^A[j])>maxi)
            maxi=A[i]^A[j];
        }
    }
    return maxi;

}