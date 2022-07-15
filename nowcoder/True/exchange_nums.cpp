#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int num_exchange(int n, vector<int>& nums) {

	int num_acts = 0;

	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] != (i + 1)) {
			swap(nums[i], nums[nums[i] - 1]);
			num_acts++;
		}
	}

	return num_acts;
}

int main(int argc, char* argv[]) {

	// @first input -- numbers of test cases;
	int k;
	cin >> k;

	// for each test cases, store them in
	vector<int> test_n;
	vector<vector<int>> test_nums;
	for (int i = 0; i < k; i++) {
		int n;
		cin >> n;
		test_n.emplace_back(n);
		vector<int> temp_holder;
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			temp_holder.emplace_back(temp);
		}

		test_nums.emplace_back(temp_holder);
	}

	// Managing the inputs
	for (int i = 0; i < test_n.size(); i++) {
		int ans = num_exchange(test_n[i], test_nums[i]);
		cout << ans << "\n";
	}

	return 1;
}