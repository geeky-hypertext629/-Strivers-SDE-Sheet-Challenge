#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
        int top1 = -1;
        int cap = 0;
        int *arr;
public:
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        cap = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(top1==cap-1)
        return;
        else
        {
            top1++;
            arr[top1] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(top1==-1)
        return -1;
        else {
          int num = arr[top1];
          top1--;
          return num;
        }
    }
    
    int top() {
        // Write your code here.
        if(top1==-1)
        return -1;
        else
        return arr[top1];
    }
    
    int isEmpty() {
        // Write your code here.
        return top1==-1;
    }
    
    int isFull() {
        // Write your code here.
        return top1==cap-1;
    }
    
};