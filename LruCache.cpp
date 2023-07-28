#include <bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int key,int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> m;
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
        head->next =tail;
        tail ->prev = head;
    }
    void addNode(Node *node1)
    {
        Node *temp = head->next;
        node1->next = temp;
        temp->prev=node1;
        node1->prev = head;
        head->next=node1;
    }
    void deleteNode(Node *node1)
    {
        Node *prev1 = node1->prev;
        Node *next1 = node1->next;
        prev1->next = next1;
        next1->prev = prev1;

    }
    int get(int key)
    {
        // Write your code here
        if(m.find(key)!=m.end())
        {
            Node *temp = m[key];
            m.erase(key);
            deleteNode(temp);
            addNode(temp);
            m[key] = head->next;
            return temp->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if (m.find(key) != m.end()) {
          Node *temp = m[key];
          m.erase(key);
          deleteNode(temp);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *ans=new Node(key,value);
        addNode(ans);
        m[key] = head -> next;
    }
};
