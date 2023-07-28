int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	//O(n) approach ---> TLE
	// int i;
	// int xor1=0;
	// for(i=0;i<arr.size();i++)
	// {
	// 	xor1^=arr[i];
	// }
	// return xor1;
	int n = arr.size();
	if(n==1)
	return arr[0];
	int left = 1;
	int right = n-2;

	if(arr[0]!=arr[1])
	return arr[0];
	if(arr[n-1]!=arr[n-2])
	return arr[n-1];

	while(left<=right)
	{
		int mid=left + (right- left)/2;

		if(arr[mid-1]!= arr[mid] && arr[mid+1]!=arr[mid])
		{
			return arr[mid];
		}
		else if(mid&1)
		{
			if(arr[mid-1]==arr[mid])
			{
				left = mid+1;
			}
			else
			{
				right = mid-1;
			}
		}
		else
		{
			if(arr[mid-1]==arr[mid])
			{
				right = mid-1;
			}
			else
			{
				left = mid+1;
			}
		}
	}
	return -1;
}