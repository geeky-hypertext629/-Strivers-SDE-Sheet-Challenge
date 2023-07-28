/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next),
 *child(child) {}
 * };
 */

Node *merge(Node *p1, Node *p2) {
  Node *t1 = new Node(0);
  Node *res = t1;
  while (p1 != NULL && p2 != NULL) {
    if (p1->data < p2->data) {
      t1->child = p1;
      t1 = t1->child;
      p1 = p1->child;
    } else {
      t1->child = p2;
      t1 = t1->child;
      p2 = p2->child;
    }
  }
  if (p1)
    t1->child = p1;
  else if(p2)
    t1->child = p2;
  return res->child;
}

// Node* merge(Node* p1, Node* p2) {
//     Node* dummy = new Node(0);
//     Node* t1 = dummy;

//     while (p1 && p2) {
//         if (p1->data < p2->data) {
//             t1->child = p1;
//             t1 = t1->child;
//             p1 = p1->child;
//         } else {
//             t1->child = p2;
//             t1 = t1->child;
//             p2 = p2->child;
//         }
//     }

//     if (p1)
//         t1->child = p1;
//     else
//         t1->child = p2;

//     return dummy->child;
// }

Node *flattenLinkedList(Node *head) {
  // Write your code here
    if(head == NULL || head->next == NULL) return head;

 

    Node* L2 = flattenLinkedList(head->next);

    head->next = NULL;

    Node* nhead = merge(head, L2);

    return nhead;
}
