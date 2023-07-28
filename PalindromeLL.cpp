#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int> v1;
    while(head!=NULL)
    {
        v1.push_back(head->data);
        head=head->next;
    }
    int n=v1.size();
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(v1[i]!=v1[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;

}