string longestCommonPrefix(vector<string> &arr, int m)
{
    // Write your code here
    string s="";
    int i;
    int n = arr[0].size();
    int x= m;
    string temp = arr[0];
    int j;
    int flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<x;j++)
        {
            if(i<arr[j].length())
            {
              if (arr[j][i] != temp[i]) {
                flag = 1;
                break;
              }
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
    if(i==n)
    return temp;
    string t(temp.begin(),temp.begin()+i);
    return t;
}


