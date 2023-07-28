vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int n = text.length();
	int m = pattern.length();
	vector<int> ans;
	int i;
	for(i=0;i<n;i++)
	{
		if(i+m-1<n)
		{
			if(text.substr(i,m)==pattern)
			ans.push_back(i+1);
		}
	}
	return ans;
}