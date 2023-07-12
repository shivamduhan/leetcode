int dfs(struct TreeNode * root, int currentSum) {
    if (!root) {return 0;}
    currentSum = currentSum * 10 + root->val;
    if (!root->right && !root->left) {return currentSum;}
    return dfs(root->left, currentSum) + dfs(root->right, currentSum);
}
int sumNumbers(struct TreeNode* root){return dfs(root,0);}
