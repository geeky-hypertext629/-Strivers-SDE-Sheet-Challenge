void takeOrNotTake(vector<vector<int>> &finalAns, vector<int> arr, vector<int> temp, int n, int k, int i)

{   //i is the iterator from 0 to n

    if (i == n)

    {

        if(k==0){

            finalAns.push_back(temp);

        }

        return;

    }

    //not including element

    takeOrNotTake(finalAns, arr, temp, n, k, i + 1);

 

    //including element

    temp.push_back(arr[i]);

 

    //calculating sum by subtracting element from k so eventually it become 0 then we can get our required subset

    takeOrNotTake(finalAns, arr, temp, n, k-arr[i], i + 1);

    return;

}

 

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)

{

    vector<vector<int>> finalAns;

    vector<int> ans;

 

    takeOrNotTake(finalAns, arr, ans, n, k, 0);

 

    return finalAns;

}

