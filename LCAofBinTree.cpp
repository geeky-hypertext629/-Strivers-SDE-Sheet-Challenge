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
TreeNode<int> *solve(TreeNode<int> *root, int x, int y) {
  if (root == NULL)
    return NULL;
  if (root->data == x || root->data == y)
    return root;
  TreeNode<int> *lca1 = solve(root->left, x, y);
  TreeNode<int> *lca2 = solve(root->right, x, y);

  if (lca1 != NULL && lca2 != NULL)
    return root;

  if (lca1 != NULL)
    return lca1;

  else
    return lca2;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
   return solve(root,x,y)->data;
}