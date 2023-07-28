#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root==NULL)
    return ans;
    queue<pair<TreeNode<int> *,int>> q1;
    q1.push({root,0});
    map<int,int> m1;
    while(!q1.empty())
    {
        pair<TreeNode<int> *,int> temp;
        temp = q1.front();
        q1.pop();
        if(m1.find(temp.second)==m1.end())
        m1[temp.second] = (temp.first)->val;
        if((temp.first)->left)
        {
            q1.push({(temp.first)->left,temp.second-1});
        } 
        if(temp.first->right)
        {
            q1.push({temp.first->right,temp.second+1});
        } 
    }
    for(auto &pr:m1)
    {
        ans.push_back(pr.second);
    }
    return ans;

}