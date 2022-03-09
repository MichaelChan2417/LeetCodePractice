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
