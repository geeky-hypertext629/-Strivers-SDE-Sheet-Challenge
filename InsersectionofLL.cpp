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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *temp = firstHead;
    int len1=0; int len2=0;
    while(temp!=NULL)
    {
        len1++;
        temp=temp->next;
    }
    temp=secondHead;
    while(temp!=NULL)
    {
        len2++;
        temp=temp->next;
    }
    if(len1>len2)
    {
        int i=0;
        while(i<(abs(len1-len2)) && firstHead!=NULL)
        {
            firstHead = firstHead->next;
            i++;
        }
    }
    else if(len2>len1)
    {
        int i=0;
        while(i<abs(len1-len2) && secondHead!=NULL)
        {
            secondHead = secondHead->next;
            i++;
        }
    }

    while(firstHead!=NULL && secondHead!=NULL)
    {
        if(firstHead==secondHead)
        {
            return firstHead;
        }
        else{
            firstHead = firstHead ->next;
            secondHead = secondHead ->next;
        }
    }
    return NULL;
}
