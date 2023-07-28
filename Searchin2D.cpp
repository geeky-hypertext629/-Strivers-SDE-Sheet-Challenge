bool isPresent(vector<int> v1,int t)
{
    int l=0;
    int h=v1.size()-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(v1[mid]==t)
        return true;
        else if(v1[mid]>t)
        h=mid-1;
        else
        l=mid+1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
        // int row = 0;
        // int col = mat[0].size();
        // while(row<mat.size() && col>=0)
        // {
        //     if(mat[row][col]==target)
        //     return true;
        //     else if(mat[row][col]<target)
        //     {
        //         row++;
        //     }
        //     else
        //     {
        //         col--;
        //     }
        // }
        // return false;

        int i;
        for(i=0;i<mat.size();i++)
        {
            if(isPresent(mat[i],target))
            return true;
        }
        return false;
}