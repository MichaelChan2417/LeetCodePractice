#include <iostream>
#include <string>
#include <queue>

#include "Tree.h"

using namespace std;


// Level Order Traversal
// Return the Tree in level's order
// the first is recursion version with O(n) time and O(n) space
void LevelComp(TreeNode* t, vector<vector<int> >& result, int level) {
	// node is nullptr; return;
	if (t == nullptr) return;

	if (level > result.size()) {
		// create a new space for insert
		vector<int> temp;
		result.push_back(temp);
	}
	result[level - 1].push_back(t->val);

	LevelComp(t->left, result, level + 1);
	LevelComp(t->right, result, level + 1);
}

vector<vector<int> > LevelOrder(TreeNode* t) {
	vector<vector<int> > result;

	LevelComp(t, result, 1);
	return result;
}

// now we complete the iterative version
vector<vector<int> > LevelOrderI(TreeNode* t) {
	vector<vector<int> > result;
	queue<TreeNode*> cur, nxt;

	if (t == nullptr) {
		return result;
	}
	else {
		cur.push(t);
	}

	while (!cur.empty()) {
		vector<int> level; // to store value in this level
		while (!cur.empty()) {
			TreeNode* node = cur.front();
			cur.pop();
			level.push_back(node->val);

			if (node->left) nxt.push(node->left);
			if (node->right) nxt.push(node->right);
		}
		result.push_back(level);
		swap(nxt, cur);
	}

	return result;
}
