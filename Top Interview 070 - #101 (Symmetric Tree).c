bool isMirror(struct TreeNode* tree1, struct TreeNode* tree2) { //generic mirror function
    if (!tree1 && !tree2) return true; //base case where traversal same
    if (!tree1 || !tree2) return false; //traversal different
    return tree1->val == tree2->val && isMirror(tree1->right, tree2->left) && isMirror(tree1->left, tree2->right);
} //need right subtree of root to be mirror image of left subtree, and left subtree to be mirror image of right subtree.
bool isSymmetric(struct TreeNode* root){return isMirror(root, root);} //dfs, check if tree is mirror of itself
