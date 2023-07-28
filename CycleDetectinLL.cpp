/****************************************************************

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


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    Node *curr = head;
    Node *fast = head;
    while(curr!=NULL && fast!=NULL && fast->next!=NULL)
    {
        curr=curr->next;
        fast=fast->next;
        fast=fast->next;
        if(curr==fast)
        return true;
    }
    return false;
}