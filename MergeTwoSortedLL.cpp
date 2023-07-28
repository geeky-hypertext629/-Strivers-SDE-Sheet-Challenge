#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* ans=NULL;
    Node<int>* head = ans;
    while(first!=NULL && second!=NULL)
    {
        Node<int>* temp = new Node<int>(2);
        if(first->data<second->data)
        {
            temp->data = first->data;
            temp->next=NULL;
            if(ans==NULL)
            {
                ans=temp;
                head=ans;
            }
            else
            {
                ans->next=temp;
                ans = temp;
            }
            first=first->next;
        }
        else
        {
            temp->data = second->data;
            temp->next=NULL;
            if(ans==NULL)
            {
                ans=temp;
                head=ans;
            }
            else
            {
                ans->next=temp;
                ans = temp;
            }
            second=second->next;
        }
    }
    if(first!=NULL)
    {
         if(ans==NULL)
            {
                ans=first;
                head=ans;
            }
            else
            {
                ans->next=first;
            }
    }
    if(second!=NULL)
    {
               if(ans==NULL)
            {
                ans=second;
                head=ans;
            }
            else
            {
                ans->next=second;
            }
    }
    return head;
}
