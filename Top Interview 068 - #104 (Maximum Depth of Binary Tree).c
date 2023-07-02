/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root){
    if (!root) {return 0;} //base case
    int left_depth = maxDepth(root->left); //height of left subtree
    int right_depth = maxDepth(root->right); //height of right subtree
    return fmax(left_depth, right_depth) + 1; //add 1 for root
}
