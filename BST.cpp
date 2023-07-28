#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public:
    stack<TreeNode<int> *> s1;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        if(root)
        pushAll(root);
    }

    int next()
    {
        // write your code here
        TreeNode<int> *temp = s1.top();
        s1.pop();
        if(temp->right)
        {
            pushAll(temp->right);
        }
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
        return !s1.empty();
    }
    void pushAll(TreeNode<int> *root)
    {
        while(root)
        {
            s1.push(root);
            root=root->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/