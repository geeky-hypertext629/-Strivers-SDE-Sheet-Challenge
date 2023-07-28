#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
void insertAtTail(LinkedListNode<int>* &cloneHead,LinkedListNode<int>* &cloneTail,int value)
{
    LinkedListNode<int>* temp = new LinkedListNode<int>(value);
    if(cloneHead==NULL)
    {
        cloneHead = temp;
        cloneTail = temp;
        return;
    }
    else
    {
        cloneTail->next = temp;
        cloneTail = cloneTail->next;
    }
}

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *cloneHead = NULL;
    LinkedListNode<int> *cloneTail = NULL;
    LinkedListNode<int> *temp = head;
    while(temp)
    {
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    map<LinkedListNode<int>*,LinkedListNode<int>*> m1;
    temp = head;
    LinkedListNode<int>* originalNode = cloneHead;
    while(temp)
    {
        m1[temp] = originalNode;
        temp = temp->next;
        originalNode = originalNode->next;
    }

    originalNode = cloneHead;
    temp = head;

    while(temp)
    {
        originalNode->random = m1[temp->random];
        originalNode = originalNode->next;
        temp=temp->next;
    }

    return cloneHead;

}
