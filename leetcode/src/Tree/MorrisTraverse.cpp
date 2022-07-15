#include <iostream>
#include <string>

#include "Tree.h"

using namespace std;


// The Morris Traverse in Tree
// Using less space 
// Using the precursor in each node to get back to its top
// the first is Morris Pre-Order

vector<int> MorrisPreOrder(TreeNode* t) {
	TreeNode* cur = t;
	TreeNode* pre;
	vector<int> result;

	while (cur != nullptr) {
		if (cur->left == nullptr) {
			// left is empty
			result.push_back(cur->val);
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while (pre->right != nullptr && pre->right != cur) {
				pre = pre->right;
			}

			if (pre->right == cur) {
				// cond .1
				pre->right = nullptr;
				cur = cur->right;
			}
			else {
				pre->right = cur;
				result.push_back(cur->val);
				cur = cur->left;
			}
		}

	}

	return result;
}


vector<int> MorrisInOrder(TreeNode* t) {
	TreeNode* cur = t;
	TreeNode* pre;
	vector<int> result;

	while (cur != nullptr) {

		// first condition find its left child
		if (cur->left == nullptr) {
			// now if it left child is null use its right child which could be
			// 1. its clue to went back
			// 2. no left child just go right for next one
			// 3. left sub-tree has been traversed, so go right
			result.push_back(cur->val);
			cur = cur->right;
		}
		else {
			// now cur has its left child, then continuous go right to find its precursor
			pre = cur->left;
			while (pre->right != nullptr && pre->right != cur) {
				pre = pre->right;
			}
			if (pre->right == cur) {
				// the clue has already been set which means the left part has all already been done
				pre->right = nullptr;
				result.push_back(cur->val);
				cur = cur->right;
			}
			else {
				// this is setting the precursor
				pre->right = cur;
				cur = cur->left;
			}
		}
	}

	return result;
}


// in Post-Order, we need one support function to complete the reverse print
void ReversePrint(vector<int>& res, TreeNode* rt) {
	TreeNode* cur = rt;
	TreeNode dummy(0);
	dummy.right = cur;
	TreeNode* prev = &dummy;
	TreeNode* nx = cur->right;

	// finish the part to reverse the whole right-edge as a linked-list
	while (cur) {
		cur->right = prev;
		prev = cur;
		cur = nx;
		if(nx != nullptr) nx = nx->right;
	}
	// 
	cur = prev;
	prev = nullptr;
	nx = cur->right;
	while (nx->right != cur) {
		res.push_back(cur->val);
		cur->right = prev;
		prev = cur;
		cur = nx;
		nx = nx->right;
	}

	// the final fix;
	res.push_back(cur->val);
	cur->right = prev;
	nx->right = nullptr;

}

vector<int> MorrisPostOrder(TreeNode* t) {
	TreeNode* cur = t;
	TreeNode* pre;
	vector<int> result;

	// first we set up the Morris in Tree
	while (cur != nullptr) {
		if (cur->left == nullptr) {
			cur = cur->right;
		}
		else {
			// it has the left sub-tree
			pre = cur->left;

			while (pre->right != nullptr && pre->right != cur) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {
				pre->right = cur; // set the clue
				cur = cur->left;
			}
			else {
				pre->right = nullptr;
				ReversePrint(result, cur->left);
				cur = cur->right;
			}
		}
	}
	// Now we have the last right version to Print
	ReversePrint(result, t);
	return result;
}






int main() {

	vector<string> pt = {"6", "2","8","1","3","7","9","#","#","4","5"};

	Tree t = Tree(pt);

	vector<int> ans = MorrisPostOrder(t.root);
	//vector<int> ans = t.PreOrder();
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
