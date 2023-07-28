#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	 stack<int> s1;
	 int i;
	 for(i=0;i<n;i++)
	 {
		 s1.push(i);
	 }
	 while(s1.size()>1)
	 {
		 int a = s1.top();
		 s1.pop();
		 
		 int b = s1.top();
		 s1.pop();

		 if(knows(a,b))
		 {
			 s1.push(b);
		 }
		 else if(knows(b,a))
		 {
			 s1.push(a);
		 }
	 }
	 if(s1.empty())
	 return -1;
	 int cele = s1.top();

	 for(i=0;i<n;i++)
	 {
		 if(i!=cele)
		 {
			 if(knows(cele,i))
			 return -1;
			 else if(!knows(i,cele))
			 return -1;
		 }
	 }
	 return cele;
}