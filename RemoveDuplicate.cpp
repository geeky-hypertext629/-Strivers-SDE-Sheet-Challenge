int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0;
	int j;
	for(j=1;j<n;j++)
	{
		if(arr[j]!=arr[j-1])
		i++;

	}
	return i+1;
}