bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root) {return false;}
    if (!root->left && !root->right) {return root->val == targetSum;}
    int newtarget = targetSum - root->val;
    return hasPathSum(root->left, newtarget) || hasPathSum(root->right, newtarget);
}
