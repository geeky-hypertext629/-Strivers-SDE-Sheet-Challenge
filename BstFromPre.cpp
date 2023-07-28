#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int> &v,int &i,int bound)
{
    if(i==v.size() || v[i]>bound)
    {
        return NULL;
    }
    TreeNode<int>* root = new TreeNode<int>(v[i++]);
    root->left = solve(v,i,root->data);
    root->right = solve(v,i,bound);
    return root;

}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    return solve(preOrder,i,INT_MAX);
}