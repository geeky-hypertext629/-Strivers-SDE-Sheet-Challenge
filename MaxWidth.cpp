#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
    return 0;
    queue<TreeNode<int> *> q1;
    q1.push(root);
    int res=0;
    int count = 0;
    int i;
    while(!q1.empty())
    {
        count = q1.size();
        res=max(res,count);
        for(i=0;i<count;i++)
        {
            TreeNode<int> *temp = q1.front();
            q1.pop();
            if(temp->left)
            {
                q1.push(temp->left);
            }
            if(temp->right)
            {
                q1.push(temp->right);
            }
        }
    }
    return res;
}