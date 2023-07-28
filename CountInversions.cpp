#include <bits/stdc++.h> 


long long invert(long long *arr,int low,int mid,int high)
{
    long long res=0;
    int n1=mid-low+1;
    int n2=high-mid;
    long long left[n1];
    long long right[n2];
    int k=low;
    int i;
    for(i=0;i<n1;i++)
    {
        left[i]=arr[low+i];
    }
    for(i=0;i<n2;i++)
    {
        right[i]=arr[mid+i+1];
    }
    i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {
            arr[k]=right[j];
            res+=(n1-i);
            j++; 
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<n1)
    {
        arr[k]=right[j];
        k++;
        j++;
    }

    return res;

}

long long solve(long long *arr,int low,int high)
{
    long long res=0;
    if(low<high)
    {
        int mid=(low+high)/2;
        res+=solve(arr,low,mid);
        res+=solve(arr,mid+1,high);
        res+=invert(arr,low,mid+1,high);
    }
    return res;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    // long long ans = solve(arr,0,n-1);
    // return ans;
       long long c=0;

    for(int i=0;i<n;i++)

    {

        for(int j=i;j<n;j++)

        {

            if(arr[i]>arr[j])

             c++;

        }

    }

    return c;

}