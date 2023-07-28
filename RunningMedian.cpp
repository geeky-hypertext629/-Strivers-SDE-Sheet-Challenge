#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>> p2;

    for(int i=0;i<n;i++){
        if(p1.empty() || p1.top()>=arr[i]) p1.push(arr[i]);
        else p2.push(arr[i]);

        if(p1.size()>p2.size()+1){
            p2.push(p1.top());
            p1.pop();
        }
        else if(p1.size()<p2.size()){
            p1.push(p2.top());
            p2.pop();
        }

        if(p2.size()<p1.size()) cout<<p1.top()<<" ";
        else cout<<(p2.top()+p1.top())/2<<" ";
    }

}