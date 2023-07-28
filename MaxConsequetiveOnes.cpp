int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i;
    int j;
    i=0;
    j=0;
    int zeroCount = 0;
    int ans = 0;
    while(j<n)
    {
        if(arr[j]==0)
        zeroCount++;
        while(zeroCount>k)
        {
            if(arr[i]==0)
            zeroCount--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}
