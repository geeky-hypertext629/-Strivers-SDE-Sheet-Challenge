class Solution {
public:
    bool canPlaceCows(vector<int> &stalls,int n,int dist,int k)
    {
        int cows = 1;
        int coordinate = stalls[0];
        int i;
        for(i=1;i<n;i++)
        {
            if((stalls[i]-coordinate)>=dist)
            {
                cows++;
                coordinate = stalls[i];
            }
           
        }
         if(cows>=k)
            {
                return true;
            }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        int low = 1;
        sort(stalls.begin(),stalls.end());
        int high = stalls[n-1] - stalls[0];
        int res = -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(canPlaceCows(stalls,n,mid,k))
            {
                res = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return res;
    }
};