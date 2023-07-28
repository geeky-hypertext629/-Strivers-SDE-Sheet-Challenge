#include <bits/stdc++.h> 

void mergeSort(vector<int> &arr,int low,int mid,int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	vector<int> b(high-low+1,0);
	while(i<=mid && j<=high)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			b[k] = arr[j];
			j++;
			k++;
		}
	}
	  while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }
    
    while (j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
	k=0;
	for(i=low;i<=high;i++)
	{
		arr[i] = b[i-low];
		// k++;
	}
}

int countPairs(vector<int> &arr ,int low,int mid,int high)
{
	int count = 0;
	int i;
	int j = mid+1;
	for(i=low;i<=mid;i++)
	{
		while(j<=high && arr[i]>2LL*arr[j])
		{
			j++;
		}
		count = count + (j-(mid+1));
	}
	return count;
}

int merge(vector<int> &arr ,int low,int high)
{
	int cnt=0;
	if(low>=high)
	return 0;
	int mid = (low+high)/2;
	cnt+=merge(arr,low,mid);
	cnt+=merge(arr,mid+1,high);
	cnt+=countPairs(arr,low,mid,high);
	mergeSort(arr,low,mid,high);
	return cnt;
}


int reversePairs(vector<int> &arr, int n){
	int ans = 0;

	ans  = merge(arr,0,n-1);

	return ans;
}