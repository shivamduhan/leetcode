void inOrder(struct TreeNode* root, struct TreeNode** prev, int* minDiff) {
    if (root == NULL) return;

    inOrder(root->left, prev, minDiff);
    
    if (*prev != NULL) {
        int currDiff = root->val - (*prev)->val;
        if (currDiff < *minDiff) {
            *minDiff = currDiff;
        }
    }
    
    *prev = root;

    inOrder(root->right, prev, minDiff);
}

int getMinimumDifference(struct TreeNode* root) {
    struct TreeNode* prev = NULL;
    int minDiff = INT_MAX;
    
    inOrder(root, &prev, &minDiff);
    
    return minDiff;
}
