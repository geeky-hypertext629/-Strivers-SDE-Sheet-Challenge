long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    long a[n+1][value+1];
    int i;
    int j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=value;j++)
        {
            if(i==0)
            a[i][j] = 0;
            if(j==0)
            a[i][j]=1;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=value;j++)
        {
            if(denominations[i-1]<=j)
            a[i][j] = a[i-1][j] + a[i][j-denominations[i-1]];
            else
            a[i][j] = a[i-1][j];
        }
    }
    return a[n][value];


}