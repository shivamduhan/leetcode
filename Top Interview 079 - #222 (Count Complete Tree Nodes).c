int countNodes(struct TreeNode* root){
    if (!root) {return 0;}
    struct TreeNode *left = root, *right = root;
    int depthleft = 0, depthright = 0;
    while (left) {
        left = left->left;
        depthleft++;
    }
    while (right) {
        right = right->right;
        depthright++;
    }
    if (depthleft == depthright) {return (1<<depthleft)-1;} //perfect binary tree, nodes = 2^depth - 1
    return 1+countNodes(root->left)+countNodes(root->right); //not perfect, recursively compute

}
