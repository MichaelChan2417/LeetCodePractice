#pragma once
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* p;
	TreeNode* left;
	TreeNode* right;

	TreeNode() :val(), p(), left(), right() {}
	TreeNode(int x) :val(x), p(nullptr), left(nullptr), right(nullptr) {}
};



struct Tree {
	TreeNode* root;

	// construction
	Tree(int x);
	Tree(vector<string> s);

	// functions
	TreeNode* Tree_Search(int x);
	void Insert(int x);
	void Delete(int x);

	vector<int> PreOrder();
	vector<int> InOrder();
	vector<int> PostOrder();

};
