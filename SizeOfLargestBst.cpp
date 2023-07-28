#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class NodeValue{
    public:
    int maxNode;
    int minNode;
    int maxSize;
    NodeValue(int a,int b,int c)
    {
        this->maxNode = b;
        this->minNode = a;
        this->maxSize = c;
    }
};

NodeValue solve(TreeNode<int>* root)
{
    if(!root)
    return NodeValue(INT_MAX,INT_MIN,0);

    auto left = solve(root->left);
    auto right = solve(root->right);

    if(left.maxNode<root->data && root->data<right.minNode)
    {
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize + right.maxSize+1);
    }
    else
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return solve(root).maxSize;
}
