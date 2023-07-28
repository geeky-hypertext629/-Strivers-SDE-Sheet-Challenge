#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
bool solve(BinaryTreeNode<int> *root, long long maxVal,long long minVal) {
    if(root==NULL)
    return true;
    if((root->data)>maxVal ||  (root->data)<minVal)
    return false;
    return solve(root->left,root->data,minVal) && solve(root->right,maxVal,root->data);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return solve(root,LONG_MAX,LONG_MIN);
}