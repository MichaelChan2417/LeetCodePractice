// find the number of the unique binary search tree
int numTrees(int n) {
	vector<int> f(n + 1, 0);
	f[0] = 1;
	f[1] = 1;
	if (n == 0 || n == 1) return 1;

	for (int i = 2; i < n + 1; i++) {
		int temp_add = 0;
		for (int j = 0; j < i; j++) {
			temp_add += f[j] * f[i - 1 - j];
		}
		f[i] = temp_add;
	}

	return f[n];
}

// then construct the binary search trees
vector<TreeNode*> generate(int start, int end) {
	vector<TreeNode*> subTree;

	// end condition
	if (start > end) {
		subTree.push_back(nullptr);
		return subTree;
	}

	for (int k = start; k < end; k++) {
		vector<TreeNode*> leftSubs = generate(start, k - 1);
		vector<TreeNode*> rightSubs = generate(k + 1, end);
		
		for (auto i : leftSubs) {
			for (auto j : rightSubs) {
				TreeNode* node = new TreeNode(k);
				node->left = i;
				node->right = j;
				subTree.push_back(node);
			}
		}

	}
	return subTree;
}

vector<TreeNode*> generateTrees(int n) {
	if (n == 0)return generate(1, 0);
	return generate(1, n);
}


// convert the sorted array to BST
template<typename RandomAccessIterator>
TreeNode* ConvertI(RandomAccessIterator first, RandomAccessIterator last) {
	const auto length = distance(first, last);

	if (length <= 0) return nullptr;

	// construct
	auto mid = first + length / 2;
	TreeNode* root = new TreeNode(*mid);
	root->left = ConvertI(first, mid);
	root->right = ConvertI(mid + 1, last);

	return root;
}

TreeNode* sortedArrayToBST(vector<int>& num) {
	ConvertI(num.begin(), num.end());
}


// Minimum Depth of the BST
int minDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}

	int left = minDepth(root->left);
	int right = minDepth(root->right);

	return (left && right) ? 1 + min(left, right) : 1 + left + right;
}


// Maximum Depth of the BST
int maxDepth(TreeNode* root) {
	if (!root) {
		return 0;
	}
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	return 1 + max(left, right);
}


// Path Sum
bool hasPathSum(TreeNode* root, int targetSum) {
	if (root == nullptr) {
		return false;
	}

	if (root->left == nullptr && root->right == nullptr) {
		return (targetSum - (root->val) == 0);
	}

	return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
}


// PathSumII, now we need the exact path to be shown.
void pathAdd(vector<vector<int> >& ans, vector<int> cur, TreeNode* root, int targetRest) {
	// End condition
	if (root == nullptr) return;

	vector<int> temp = cur;
	temp.push_back(root->val);

	if ((root->left == nullptr) && (root->right == nullptr)) {
		if (targetRest == root->val) {
			ans.push_back(temp);
		}
		return;
	}

	pathAdd(ans, temp, root->left, targetRest - root->val);
	pathAdd(ans, temp, root->right, targetRest - root->val);

}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int> > ans;

	if (!root) return ans;

	vector<int> cur;

	pathAdd(ans, cur, root, targetSum);

	return ans;
}


// PathSumIII now find the poss
unordered_map<long long, int> prefix;

int prefix_handler(TreeNode* root, int targetSum, long long curr) {
	if (!root) return 0;

	curr += root->val;

	int ret = 0;
	if (prefix.count(curr - targetSum)) {
		ret = prefix[curr - targetSum];
	}

	prefix[curr]++;
	ret += prefix_handler(root->left, targetSum, curr);
	ret += prefix_handler(root->right, targetSum, curr);
	prefix[curr]--;

	return ret;
}

int pathSumIII(TreeNode* root, int targetSum) {
	prefix[0] = 1;
	return prefix_handler(root, targetSum, 0);
}
