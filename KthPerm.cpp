#include<bits/stdc++.h>

string kthPermutation(int n, int k) {
    // Write your code here.
    // vector<int> temp;
    // int i;
    // for(i=1;i<=n;i++)
    // {
    //     temp.push_back(i);
    // }
    // int count = 1;
    // do{
    //     if(count==k)
    //     break;
    //     count++;
    // }while(next_permutation(temp.begin(),temp.end()));

    // string s="";

    // for(i=0;i<n;i++)
    // {
    //     s.push_back('0'+temp[i]);
    // }
    // return s;


    int i;
    vector<int> temp; 
    int fact = 1;
    for(i=1;i<n;i++)
    {
        temp.push_back(i);
        fact = fact*i;
    }
    temp.push_back(n);
    string ans="";
    k=k-1;
    while(true)
    {
        ans+=(to_string(temp[k/fact]));
        temp.erase(temp.begin() + k/fact);
        if(temp.size()==0)
        break;
        k=k%fact;
        fact = fact/temp.size();
    }
    return ans;
}
