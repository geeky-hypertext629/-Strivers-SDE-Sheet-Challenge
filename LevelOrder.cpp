#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
// vector<int> temp;
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    queue<BinaryTreeNode<int> *> q1;
    q1.push(root);
    vector<int> ans;
    if(root==NULL)
    return ans;
    ans.push_back(root->val);
    while(!q1.empty())
    {
        BinaryTreeNode<int> *temp = q1.front();
        q1.pop();
        if(temp->left)
        {
            ans.push_back((temp->left)->val);
            q1.push(temp->left);
        }
        if(temp->right)
        {
            ans.push_back((temp->right)->val);
            q1.push(temp->right);
        }
    }
    return ans;

}