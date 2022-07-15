#include <iostream>
#include <string>
#include <vector>

#include "Tree.h"

using namespace std;

// here we use the morris inorder traverse, so that the space usage is O(1)
// the support function to used for swap in the final state.
void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* cur) {
	if (prev != nullptr && prev->val > cur->val) {
		if (broken.first == nullptr) {
			broken.first = prev;
		}
		broken.second = cur;
	}
}

// Recover the BST, in the BST one pair of nodes have been swapped, fix it
void RecoverTree(TreeNode* t) {
	pair<TreeNode*, TreeNode*> broken;
	TreeNode* prev = nullptr;
	TreeNode* cur = t;

	while (cur != nullptr) {
		if (cur->left == nullptr) {
			detect(broken, prev, cur);
			prev = cur;
			cur = cur->right;
		}
		else {
			auto temp = cur->left;

			while (temp->right != nullptr && temp->right != cur) {
				temp = temp->right;
			}
			if (temp->right == nullptr) {
				temp->right = cur;
				cur = cur->left;
			}
			else {
				detect(broken, prev, cur);
				temp->right = nullptr;
				prev = cur;
				cur = cur->right;
			}
		}
	}
	auto G = broken.first->val;
	broken.first->val = broken.second->val;
	broken.second->val = G;
}
