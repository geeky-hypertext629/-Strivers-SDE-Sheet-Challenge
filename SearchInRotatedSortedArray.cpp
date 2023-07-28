int search(int* arr, int n, int x) {
    // Write your code here.
    int l=0;
    int h = n-1;
    while(l<=h)
    {
        int mid = (l + h)/2;
        if(arr[mid]==x)
        return mid;
        else if(arr[l]<=arr[mid])
        {
            if(x>=arr[l] && x<=arr[mid])
            {
                h=mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        else{
            if(x>=arr[mid] && x<=arr[h])
            {
                l=mid+1;
            }
            else
            {
                h = mid-1;
            }
        }
    }
    return -1;
}