#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int>* root,vector<int> &ans)
{
    if(root==NULL)
    return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here
    vector<int> ans;
    inorder(root,ans);
    int i;
    pair<int,int> res;
    for(i=0;i<ans.size();i++)
    {
        if(ans[i]==key)
        {
            if(i==0)
            {
                res.first = -1;
            }
            else
            {
                res.first = ans[i-1];
            }
            if(i==ans.size()-1)
            {
                res.second=-1;
            }
            else
            {
                res.second=ans[i+1];
            }
        }
    }
    return res;
}
