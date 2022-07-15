void flatten(TreeNode* root) {
    if(root == nullptr) return;
    TreeNode* cur = root;
    TreeNode* next;
    TreeNode* trav;
    while(cur != nullptr){
        if(cur->left == nullptr){
            cur = cur->right;
            continue;
        }
        // Add in the left node first;
        next = cur->right;
        cur->right = cur->left;
        cur->left = nullptr;

        trav = cur;
        while(trav->right != nullptr){
            trav = trav->right;
        }
        trav->right = next;
        cur = cur->right;

    }
}
