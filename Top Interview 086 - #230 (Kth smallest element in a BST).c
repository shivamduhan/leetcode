int count = 0, result = 0;
void traverse(struct TreeNode * root, int k) { //in order traversal, visit nodes in ascending order
    if (root->left){traverse(root->left, k);}
    count++;
    if (count == k){ //current node kth smallest node
        result = root->val;
        return;}
    if (root->right){traverse(root->right, k);}
}
int kthSmallest(struct TreeNode* root, int k){
    count = 0; //count is a global variable, need to reset
    traverse(root, k);
    return result;
}
