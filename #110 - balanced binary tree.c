int height(struct TreeNode* root) {
    if (!root) return 0;
    int leftheight = height(root->left); int rightheight = height(root->right);
    return 1 + (leftheight>rightheight ? leftheight : rightheight);
}
bool isBalanced(struct TreeNode* root){
    if (!root) return true;
    if (abs(height(root->left) - height(root->right)) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
