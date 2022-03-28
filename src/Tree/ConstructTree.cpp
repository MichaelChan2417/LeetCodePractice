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


// now construct the tree using preorder and inorder
void constructTree1(vector<int>& preorder, vector<int>& inorder, TreeNode* r) {
    int r_val = r->val;
    int index = 0;
    if (preorder.size() == 1) {
        return;
    }
    for (; index < inorder.size(); index++) {
        if (inorder[index] == r_val) {
            break;
        }
    }
    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + index);
    vector<int> right_preorder(preorder.begin() + 1 + index, preorder.end());

    vector<int> left_inorder(inorder.begin(), inorder.begin() + index);
    vector<int> right_inorder(inorder.begin() + index + 1, inorder.end());

    if (!left_preorder.empty()) {
        TreeNode* temp_node = new TreeNode(left_preorder[0]);
        r->left = temp_node;
        constructTree1(left_preorder, left_inorder, r->left);
    }
    if (!right_preorder.empty()) {
        TreeNode* temp_node = new TreeNode(right_preorder[0]);
        r->right = temp_node;
        constructTree1(right_preorder, right_inorder, r->right);
    }
};

// This is building tree from the preorder and inorder.
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    constructTree1(preorder, inorder, root);
    return root;
}
