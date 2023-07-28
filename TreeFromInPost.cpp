#include <bits/stdc++.h>

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* solve(vector<int> &postOrder, vector<int> &inOrder,int is,int ie,int ps,int pe,map<int,int> &m1)
{
  if(ps>pe || is>ie)
  return NULL;
  TreeNode<int>* ans = new TreeNode<int>(postOrder[pe]);
  int indInorder = m1[ans->data];
  int interval = indInorder - is;
  ans->left = solve(postOrder,inOrder,is,indInorder-1,ps,ps + interval-1,m1);
  ans->right = solve(postOrder,inOrder,indInorder+1,ie,ps + interval,pe-1,m1);
  return ans;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
  if(inOrder.size()!=postOrder.size())
  return NULL;
  int n = postOrder.size();
  int i;

  map<int,int> m1;

  for(i=0;i<n;i++)
  {
    m1[inOrder[i]] = i;
  }

  return solve(postOrder,inOrder,0,n-1,0,n-1,m1);

}
