int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>> matrix(n,vector<int>(n,1e9));
    int i;
    for(i=0;i<n;i++)
    {
        matrix[i][i]=0;
    }
    for(auto &pr:edges)
    {
        int u=pr[0]-1;
        int v=pr[1]-1;
        int w=pr[2];
        matrix[u][v]=w;
    }
        for(int k=0;k<n;k++)

    {

        for(i=0;i<n;i++)

        {

            for(int j=0;j<n;j++)

            {

                 if(matrix[i][k] !=1e9 and matrix[k][j] !=1e9){

                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);

              }

             }

 

        }

    }

    return matrix[src-1][dest-1];

}