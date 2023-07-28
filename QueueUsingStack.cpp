class Queue {
    // Define the data members(if any) here.
    stack<int> s1;
    stack<int> s2;
    int size;
    public:
    Queue() {
        // Initialize your data structure here.
        size=0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        s1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function
        if(s1.empty() && s2.empty())
        return -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        // Implement the peek() function here.
        if(s1.empty() && s2.empty())
        return -1;
        
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int x = s1.top();
                s1.pop();
                s2.push(x);
            }
        }
        int x = s2.top();
        return x;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return s1.empty() && s2.empty();
    }
};