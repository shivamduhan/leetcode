struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root){return NULL;}
    if (root == p || root == q) {return root;}
    struct TreeNode * right = lowestCommonAncestor(root->right, p, q); //post order traversal (recurse right and left)
    struct TreeNode * left = lowestCommonAncestor(root->left, p, q);
    if (left && right) {return root;} //one node found in left subtree, other in right subtree
    return left ? left : right;    //either left or right null i.e. both in 1 subtree
}
