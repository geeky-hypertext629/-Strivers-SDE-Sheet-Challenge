#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	// Write your code here.
	stack<pair<int,int>> s1;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
			
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
			pair<int,int> p;
			p.first = num;
			if(!s1.empty())
			{
				if(s1.top().second<num)
				{
					p.second = s1.top().second;
				}
				else
				{
					p.second = num;
				}
			}
			else
			{
					p.second = num;
			}
			s1.push(p);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
			if(s1.empty())
			return -1;
			int x= s1.top().first;
			s1.pop();
			return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
			if(s1.empty())
			return -1;
			return s1.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
			if(s1.empty())
			return -1;
			return s1.top().second;
		}
};