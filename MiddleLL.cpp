/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    // Write your code here
    Node *curr=head;
    Node *next=head;
    while(next!=NULL && next->next!=NULL)
    {
        curr=curr->next;
        next=next->next;
        next=next->next;
    }
    return curr;
}

