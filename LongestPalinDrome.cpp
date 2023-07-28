string longestPalinSubstring(string str)
{
    // Write your code here.
    int i;
    int pos1=-1;
    int pos2=-1;
    int n = str.length();
    int l,r;
    int res= 0;
    for(i=0;i<n;i++)
    {
        l=i;
        r=i;
        while(l>=0 && r<n && str[l]==str[r])
        {
          if (r - l + 1 > res) {
            res = r - l + 1;
            pos1 = l;
            pos2 = r;
          }
            l--;
            r++;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<n && str[l]==str[r])
        {
          if (r - l + 1 > res) {
            res = r - l + 1;
            pos1 = l;
            pos2 = r;
          }
            l--;
            r++;
        }
    }
    return str.substr(pos1,res);
    
}