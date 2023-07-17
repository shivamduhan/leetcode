bool isValid(struct TreeNode* root, struct TreeNode* minNode, struct TreeNode* maxNode){
    if (!root) {return true;}
    if (minNode && root->val <= minNode->val) {return false;}
    if (maxNode && root->val >= maxNode->val) {return false;}
    return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
}
bool isValidBST(struct TreeNode* root){return isValid(root, NULL, NULL);}
