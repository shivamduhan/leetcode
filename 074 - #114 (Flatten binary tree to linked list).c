void flatten(struct TreeNode* root){
    if (!root) {return;}
    flatten(root->right);
    flatten(root->left);
    struct TreeNode *tmp = root->right; //store flat right subtree
    root->right = root->left; //connect root with flattened left
    root->left = NULL; //root must be leftmost
    struct TreeNode *curr = root;
    while (curr->right){curr=curr->right;} //traverse to end of new linked list
    curr->right=tmp;} //connect end of linked list to right subtree
