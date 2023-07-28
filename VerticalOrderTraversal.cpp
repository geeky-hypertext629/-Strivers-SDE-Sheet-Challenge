#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<pair<TreeNode<int> *,int>> q1;
    q1.push({root,0});
    map<int,vector<int>> m1;
    vector<int> ans;
    if(root==NULL)
    return ans;
    while(!q1.empty())
    {
        TreeNode<int> *temp = q1.front().first;
        int hd = q1.front().second;
        q1.pop();
        m1[hd].push_back(temp->data);
        if(temp->left)
        {
            q1.push({temp->left,hd-1});
        }
        if(temp->right)
        {
            q1.push({temp->right,hd+1});
        }
    }
    for(auto &pr:m1)
    {
        for(auto &x:pr.second)
        {
            ans.push_back(x);
        }
    }
    return ans;
}