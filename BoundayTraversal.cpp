#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root)
{
    if(root->left==NULL && root->right==NULL)
    return true;
    return false;
}


void getLeftNodes(TreeNode<int>* root,vector<int> &ans)
{
    TreeNode<int>* curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr))
        ans.push_back(curr->data);
        if(curr->left)
        curr = curr->left;
        else
        curr = curr->right;
    }
}
void getRightNodes(TreeNode<int>* root,vector<int> &ans)
{
    TreeNode<int>* curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))
        temp.push_back(curr->data);
        if(curr->right)
        curr = curr->right;
        else
        curr = curr->left;
    }
    int i;
    for(i=temp.size()-1;i>=0;i--)
    {
        ans.push_back(temp[i]);
    }
}

void getLeafNodes(TreeNode<int> *root, vector<int> &ans) {
    if(root)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
        }
        getLeafNodes(root->left,ans);
        getLeafNodes(root->right,ans);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL)
    return ans;
    if(!isLeaf(root))
    ans.push_back(root->data);
    getLeftNodes(root,ans);
    getLeafNodes(root,ans);
    getRightNodes(root,ans);
    return ans;
}