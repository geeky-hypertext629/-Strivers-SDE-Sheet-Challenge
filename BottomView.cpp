#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<BinaryTreeNode<int> *,int>> q1;
    vector<int> ans;
    q1.push({root,0});
    map<int,int> m1;
    while(!q1.empty())
    {
        BinaryTreeNode<int> *temp = q1.front().first;
        int line = q1.front().second;
        q1.pop();
        m1[line] = temp->data;
        if(temp->left)
        {
            q1.push({temp->left,line-1});
        }
        if(temp->right)
        {
            q1.push({temp->right,line+1});
        }
    }
    for(auto &pr:m1)
    {
        ans.push_back(pr.second);
    }
    return ans;
    
}
