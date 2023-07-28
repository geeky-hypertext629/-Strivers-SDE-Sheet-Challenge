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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    queue<BinaryTreeNode<int> *> q1;
    vector<int> ans;
    if(root==NULL)
    return ans;
    q1.push(root);
    int i;
    int track  = 0;
    while(!q1.empty())
    {
        int n = q1.size();
        vector<int> temp;
        for(i=0;i<n;i++)
        {
            BinaryTreeNode<int> *t1 = q1.front();
            q1.pop();
            temp.push_back(t1->data);
            if(t1->left)
            {
                q1.push(t1->left);
            }
            if(t1->right)
            {
                q1.push(t1->right);
            }
        }
        if(track&1)
        reverse(temp.begin(),temp.end());
        for(auto x:temp)
        ans.push_back(x);
        track++;
    }
    return ans;
}
