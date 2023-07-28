#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node * solve(Node *head, int n, int b[],int i)
{
	if(head==NULL)
	return NULL;
	int count = 0;
	Node *curr = head;
	Node *next = NULL;
	Node *prev = NULL;
	if(i>=n)
	return head;
	if(b[i]==0)
	{
		return solve(head,n,b,i+1);
	}
	int k = b[i];

	while(curr!=NULL && count<k)
	{
		next  = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(next!=NULL)
	{
		head->next =  solve(next,n,b,i+1);
	}
	return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	int initial = 0;
	return solve(head,n,b,0);
}