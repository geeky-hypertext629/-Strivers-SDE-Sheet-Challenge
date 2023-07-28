#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void solve(BinaryTreeNode<int> *root,vector<int> &temp)
{
    if(root==NULL)
    return;
    solve(root->left,temp);
    temp.push_back(root->data);
    solve(root->right,temp);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> temp;
    solve(root,temp);
    int i = 0;
    int j = temp.size()-1;
    while(i<j)
    {
        int sum = temp[i] + temp[j];
        if(sum==k)
        return true;
        else if(sum<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}