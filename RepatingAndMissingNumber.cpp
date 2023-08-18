vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long sumOfN = (n*(n+1))/2;
    long long sumOfN2 = (n*(n+1)*(2*n+1))/6;
    long long i;
    long long sum = 0;
    long long sum2 = 0;
    for(i=0;i<n;i++){
        sum+=A[i];
        sum2+=A[i]*1LL*A[i];
    }
    
    long long val1 = sum - sumOfN;
    long long val2 = sum2 - sumOfN2;
    
    val2 = val2/val1;
    long long x=(val1+val2)/2;
    
    long long y= x - val1;
    
    return {int(x),int(y)};
    
    }
