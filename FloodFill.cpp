
void solve(int x,int y,vector<vector<int>> &ans,vector<vector<int>> &image,int initial,int newColor,int delRow[],int delCol[])
{
        ans[x][y] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = x + delRow[i]; 
            int ncol = y + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == initial && ans[nrow][ncol] != newColor) {
                solve(nrow, ncol, ans, image, initial,newColor, delRow, delCol); 
            }
        }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector<vector<int>> ans =image;
    int initial = image[x][y];
     int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
    solve(x,y,ans,image,initial,newColor,delRow,delCol);
    return ans;

}