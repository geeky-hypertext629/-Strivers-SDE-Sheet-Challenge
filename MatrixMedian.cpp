#include <bits/stdc++.h>

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int midPos = (n*m+1)/2;
    int mini = matrix[0][0];
    int maxi = matrix[0][m-1];
    int i;
    for(i=0;i<n;i++)
    {
        if(matrix[i][0]<mini)
        mini = matrix[i][0];
        if(matrix[i][m-1]>maxi)
        maxi = matrix[i][m-1];
    }
    while(mini<maxi)
    {
        int mid = (maxi + mini )/2;
        int medPos = 0;
        int j;
        for(j=0;j<n;j++)
        {
            int index=(upper_bound(matrix[j].begin(),matrix[j].end(),mid) - matrix[j].begin());
            medPos+=index;
        }
        if(medPos<midPos)
        {
            mini = mid+1;
        }
        else
        {
            maxi = mid;
        }
    }
    return mini;
}