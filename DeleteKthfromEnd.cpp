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

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int len=0;
    Node *curr = head;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    int target = len-K+1;
    int temp=1;
    if(target==1)
    {
        head=head->next;
        return head;
    }
    curr=head;
    Node *ans=curr;
    Node *prev=NULL;
    while(curr!=NULL)
    {
        if(temp==target)
        {
            prev->next=curr->next;
            Node *temp1 = curr;
            curr=curr->next;
            temp1->next=NULL;
            free(temp1);
        }
        else{
            prev = curr;
            curr=curr->next;
        }
        temp++;

    }
    return ans;
}
