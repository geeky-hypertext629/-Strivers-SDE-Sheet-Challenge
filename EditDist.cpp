int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &t)
{
    if(i==s1.length())
    {
        return s2.length()-j;
    }
    if(j==s2.length())
    {
        return s1.length()-i;
    }
    if(t[i][j]!=-1)
    return t[i][j];
    int ans = 0;
    if (s1[i] == s2[j]) // Characters are the same, move to the next ones
    {
        return solve(s1, s2, i + 1, j + 1,t);
    } else {

      int dele = 1 + solve(s1, s2, i + 1, j,t);
      int ins = 1 + solve(s1, s2, i, j + 1,t);
      int replace = 1 + solve(s1, s2, i + 1, j + 1,t);
    ans = min(dele,min(ins,replace));
    }

    return t[i][j]= ans;
}

int editDistance(string str1, string str2)
{
    //write you code here
    vector<vector<int>> dp(str1.length()+1,vector<int>(str2.length()+1,-1));
    return solve(str1,str2,0,0,dp);
}