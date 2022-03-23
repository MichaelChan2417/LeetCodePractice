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

