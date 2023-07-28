/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool solve(BinaryTreeNode<int>* l,BinaryTreeNode<int>* r)
{
    if(l==NULL || r==NULL)
    return l==r;
    return (l->data == r->data) && solve(l->right,r->left) && solve(l->left,r->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.  
    if(root==NULL)
    return true;
    return solve(root->left,root->right);
}