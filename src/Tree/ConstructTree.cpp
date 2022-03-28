// construct tree using preorder
// my solution
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    TreeNode* cur = root;
    stack<TreeNode* > stk;
    stk.push(cur);

    for (int i = 1; i < preorder.size(); i++) {
        TreeNode* temp_node = new TreeNode(preorder[i]);

        // construct the left part
        if (preorder[i] < stk.top()->val) {
            stk.push(temp_node);
            cur->left = temp_node;
            cur = cur->left;
        }
        // construct the right part
        else {
            TreeNode* prev = stk.top();
            stk.pop();

            while (!stk.empty()) {
                cur = stk.top();
                stk.pop();
                if (cur->val < preorder[i]) {
                    prev = cur;
                    continue;
                }
                else {
                    prev->right = temp_node;
                    stk.push(cur);
                    stk.push(temp_node);
                    cur = temp_node;
                    break;
                }
            }

            if (stk.empty()) {
                cur->right = temp_node;
                cur = temp_node;
                stk.push(temp_node);
            }
        }
    }
    return root;
}


// Here we use another way to complete the function
void constructTree(TreeNode* r, vector<int>& preorder, int i, int j) {
    // if only one left
    int r_val = r->val;
    int k = 0;

    if (i > j) return;
    if (i == j) {
        TreeNode* temp_node = new TreeNode(preorder[i]);
        if (r_val < preorder[i]) {
            r->right = temp_node;
        }
        else {
            r->left = temp_node;
        }
        return;
    }

    for (k = i; k <= j; k++) {
        if (preorder[k] > r_val) {
            break;
        }
    }

    if (k == i) {
        TreeNode* temp_node = new TreeNode(preorder[k]);
        r->right = temp_node;
        constructTree(r->right, preorder, k + 1, j);
    }
    else if (k == j + 1) {
        TreeNode* temp_node = new TreeNode(preorder[i]);
        r->left = temp_node;
        constructTree(r->left, preorder, i + 1, j);
        return;
    }
    else {
        TreeNode* temp_node1 = new TreeNode(preorder[i]);
        TreeNode* temp_node2 = new TreeNode(preorder[k]);
        r->left = temp_node1;
        r->right = temp_node2;
        constructTree(r->left, preorder, i + 1, k - 1);
        constructTree(r->right, preorder, k + 1, j);
        return;
    }

};


TreeNode* bstFromPreorder2(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    int n = preorder.size();
    constructTree(root, preorder, 1, n - 1);
    return root;
};
