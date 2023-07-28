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

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *first = head;
    Node *second = head;
    while(first!=NULL && second!=NULL){

        second=second->next;

        if (second != NULL) {

          second = second->next;
        }

        first=first->next;

        if (first == second) {

          break;
        }
    }
    if(first==NULL || second==NULL)
    return NULL;
    first=head;
    while(first!=second)
    {
        first=first->next;
        second=second->next;
    }
    return first;
}