# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

int mcm(vector<int> &arr, int n){
	int **minMul = (int **)malloc(sizeof(int*)*n);

	int i, j, k, L, q;
	for(i=0;i<n;i++)
	{
		minMul[i] = (int *)malloc(sizeof(int)*n);
	}
	for(i=1; i<n; i++){
		minMul[i][i] = 0;
	}
	for(L=2; L<n; L++){
		for(i=1; i<n-L+1; i++){
			j = i+L-1;
			minMul[i][j] = INT_MAX;
			for(k=i; k<=j-1; k++){
				q=minMul[i][k] + minMul[k+1][j] + arr[i-1]*arr[k]*arr[j];
				if(q<minMul[i][j]){
					minMul[i][j] = q;
				}
			}
		}
	}
	return minMul[1][n-1];
}

// int main(){

// 	int n, i;
// 	printf("Enter the size of array \n");
// 	scanf("%d", &n);
// 	printf("Enter the sequences\n");
// 	int *arr = (int *)malloc(sizeof(int)*n);
// 	for(i=0; i<n; i++){
// 		scanf("%d", &arr[i]);
// 	}

// 	printf("min no. of mult. is %d\n", mcm(arr, n));
// 	printf("\n");
// 	return 0;
// }

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    mcm(arr, N);
}