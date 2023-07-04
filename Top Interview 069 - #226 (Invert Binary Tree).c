struct TreeNode* invertTree(struct TreeNode* root){
    if (!root) {return NULL;} //input validation
    struct TreeNode * temp = root -> left; //swap left child and right child
    root->left = root->right;
    root->right=temp;
    invertTree(root->left); //recursively invert left
    invertTree(root->right); //and right subtree
    return root; 
}
