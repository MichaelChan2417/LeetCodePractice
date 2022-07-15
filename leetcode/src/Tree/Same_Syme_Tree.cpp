#include <iostream>
#include <string>
#include <vector>

#include "Tree.h"

using namespace std;


// The function detect whether two trees are the same or not/
bool isSameTree(TreeNode* p, TreeNode* q) {
	if (!p && !q) return true; // this means the left end
	else if (!p || !q) return false;

	return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}

// The function detect whether two trees are symmetric
bool isSymmetric(TreeNode* p, TreeNode* q) {
	if (!p && !q) return true; // this means the left end
	else if (!p || !q) return false;

	return (p->val == q->val) && (isSameTree(p->left, q->right)) && (isSameTree(p->right, q->left));
}

// Function detect whether the tree is balanced
int NodeDepth(TreeNode* x) {
	if (x == nullptr) return 0;

	int l = NodeDepth(x->left);
	int r = NodeDepth(x->right);

	if (l < 0 || r < 0 || abs(l - r)>1) return -1;

	return max(l, r) + 1;
}

bool BalancedTree(TreeNode* p) {
	return (NodeDepth(p) >= 0);
}
