/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *l1, Node *l2)
{
    // Write your code here.
    int carry=0;
        struct Node* ans=NULL;
        struct Node* last=ans;
        ans=last;
        int sum=0;
        struct Node* t;
        while(l1!=NULL && l2!=NULL)
        {
            t=new Node();
            sum=carry+l1->data+l2->data;
            t->data=sum%10;
            t->next=NULL;
            if(ans==NULL)
            {
                ans=t;
                last=ans;
            }
            else
            {
                last->next=t;
                last=t;
            }
            l1=l1->next;
            l2=l2->next;
            carry=sum/10;
            sum=0;
        }
        while(l1!=NULL)
        {
            sum=carry+l1->data;
            t=new Node();
            t->data=sum%10;
            t->next=NULL;
            carry=sum/10;
             if(ans==NULL)
            {
                ans=t;
                 last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
            l1=l1->next;
            sum=0;
        }
        while(l2!=NULL)
        {
            sum=carry+l2->data;
            t=new Node();
            t->data=sum%10;
            t->next=NULL;
            carry=sum/10;
             if(ans==NULL)
            {
                ans=t;
                 last=t;
            }
            else
            {
                last->next=t;
                last=t;
            }
            l2=l2->next;
            sum=0;
        }
        
        if(carry!=0)
        {
             t=new Node();
             t->data=carry;
             t->next=NULL;
             last->next=t;
             last=t;
        }
        return ans;
    }
