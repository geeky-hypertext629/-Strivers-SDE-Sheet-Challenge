#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void getinor(BinaryTreeNode<int> *root,vector<int> &inorder)
{
    if(root)
    {
        getinor(root->left,inorder);
        inorder.push_back(root->data);
        getinor(root->right,inorder);
    }
}
void getpre(BinaryTreeNode<int> *root,vector<int> &preorder)
{
    if(root)
    {
        preorder.push_back(root->data);
        getpre(root->left,preorder);
        getpre(root->right,preorder);
    }
}
void getpost(BinaryTreeNode<int> *root,vector<int> &postorder)
{
    if(root)
    {
        getpost(root->left,postorder);
        getpost(root->right,postorder);
        postorder.push_back(root->data);
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    getpre(root,preorder);
    getinor(root,inorder);
    getpost(root,postorder);
    vector<vector<int>> ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
    
}