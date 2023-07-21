struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0) {return NULL;}
    struct TreeNode * root = (struct TreeNode *) malloc(sizeof(struct TreeNode));
    int mid = numsSize / 2; //sorted array
    root->val = nums[mid];
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - (mid+1)); //start from after midpt
    return root;
}
