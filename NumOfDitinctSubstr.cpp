#include <bits/stdc++.h> 
int distinctSubstring(string &word) {
    //  Write your code here.
    set<string> ans;
    int i;
    int j;

    for(i=0;i<word.size();i++)
    {
        string temp="";
        for(j=i;j<word.size();j++)
        {
            temp.push_back(word[j]);
            ans.insert(temp);
        }
    }
    return ans.size();
}
