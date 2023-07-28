#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int i;
	int j;
	int x=matrix.size();
	int y=matrix[0].size();
	vector<int> temp1(x,0);
	vector<int> temp2(y,0);
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(matrix[i][j]==0)
			{
				temp1[i]++;
				temp2[j]++;
			}
		}
	}
	for(i=0;i<x;i++)
	{
          for (j = 0; j < y; j++) {
            if (temp1[i] != 0 || temp2[j] != 0)
              matrix[i][j] = 0;
          }
        }
}