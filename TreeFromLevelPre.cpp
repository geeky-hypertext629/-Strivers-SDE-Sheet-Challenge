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
int findinInorder(vector<int> inorder,int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(inorder[i]==num)
        return i;
    }
    return -1;
}


TreeNode<int> * solve(vector<int> inorder, vector<int> preorder,int &index,int start,int end,int n)
{
    if(index>=n || start>end)
    return NULL;
    int preNum = preorder[index];
    index++;
    int inIndex = findinInorder(inorder,n,preNum);
    TreeNode<int> *root = new TreeNode<int>(preNum);
    root->left = solve(inorder,preorder,index,start,inIndex-1,n);
    root->right = solve(inorder,preorder,index,inIndex+1,end,n);
    return root;
}



TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preOrderIndex = 0;
    int n = preorder.size();

    TreeNode<int> *ans = solve(inorder,preorder,preOrderIndex,0,n-1,n);
    return ans;
}