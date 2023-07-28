int solve(vector<int> &values, vector<int> &weights, int n, int w,vector<vector<int>> &t)
{
	if(n==0 || w==0)
	{
		return t[n][w] = 0;
	}
	if(t[n][w]!=-1)
	return t[n][w];
	else if(weights[n-1]<=w)
	{
		return t[n][w] = max(values[n-1]+solve(values, weights,n-1,w-weights[n-1],t),solve(values, weights,n-1,w,t));
	}
	else 
	{
		return t[n][w] = solve(values, weights,n-1,w,t); 
	}
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> t(n + 1, vector<int>(w + 1, -1));
	return solve(values,weights,n,w,t);
}