



vector<int> subsetSum(vector<int> &num){
	//Using Bit Manipulation
	int n = 1<<num.size();
	int i;
	int pos=0;
	vector<int> ans;
	for(i=0;i<n;i++)
	{
		int sum = 0;
		for(int j=0;j<num.size();j++)
		{
			if((i&(1<<j))!=0)
			sum+=num[j];
		}
		ans.push_back(sum);
	}
	sort(ans.begin(),ans.end());
	return ans;
}