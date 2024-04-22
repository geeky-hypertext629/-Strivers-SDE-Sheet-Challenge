class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool canPlaceBooks(int a[],int n,int m,int barrier)
    {
        int studs=1;
        int pages=0;;
        int i;
        for(i=0;i<n;i++)
        {
            if(a[i]>barrier)
            {
                return false;
            }
            if(pages+a[i]<=barrier)
            {
                pages +=a[i];
            }
            else
            {
                pages = a[i];
                studs++;
            }
        }
        
        if(studs>m)
        return false;
        return true;
        
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        // sort(A,A+N);
        int low =*min_element(A,A+N);
        int high=0;
        int i;
        for(i=0;i<N;i++)
        {
            high+=A[i];
        }
        if(M>N)
        return -1;
        int res=-1;
        
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(canPlaceBooks(A,N,M,mid))
            {
                res = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return res;
    }
};