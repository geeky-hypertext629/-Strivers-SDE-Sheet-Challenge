#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    public:
    queue<int> q1;
    queue<int> q2;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void push(int element) {
        q2.push(element);
        while(!q1.empty())
        {
            int ele = q1.front();
            q1.pop();
            q2.push(ele);
        }
        swap(q1,q2);
}

    int pop() {
        if(q1.empty())
        return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        if(q1.empty())
        return -1;
        return q1.front();        
    }
};