#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int front1;
    int rear;
public:
    Queue() {
        // Implement the Constructor
        arr=new int[10001];
        front1 = -1;
        rear=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear==-1 || front1>rear)
        return true;
        else
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        rear++;
        if(front1 ==-1)
        front1++;
        arr[rear] = data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==-1 || front1>rear)
        {
            return -1;
        }
        else
        {
            int x= arr[front1];
            front1++;
            return x;
        }
    }

    int front() {
        // Implement the front() function
        if(front1==-1 || front1>rear)
        return -1;
        else
        {
            return arr[front1];
        }
    }
};