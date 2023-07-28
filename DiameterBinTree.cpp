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
int height(TreeNode<int> *root)
{
    if(root==NULL)
    return 0;
    return 1 + max(height(root->left),height(root->right));
}


int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(root==NULL)
    return 0;

    int d1 = height(root->left) + height(root->right);
    int d2 = diameterOfBinaryTree(root->left);
    int d3 = diameterOfBinaryTree(root->right);

    return max(d1,max(d2,d3));
}
