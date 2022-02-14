// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// my first solution:
int SingleNonDupOrdered(vector<int>& nums) {
	int n = nums.size();
	if (n == 1) return nums[0];
	int l = 0;
	int r = n - 1;

	while (l < r - 2) {
		int mid = (r - l) / 2 + l;
		if ((nums[mid] != nums[mid + 1]) && (nums[mid] != nums[mid - 1])) {
			return nums[mid];
		}
		else if (nums[mid] == nums[mid ^ 1]) {
			l = max(mid, mid ^ 1) + 1;
		}
		else {
			r = mid - 2 + (mid % 2);
		}
	}
	if (nums[l] == nums[l + 1]) {
		return nums[r];
	}
	else {
		return nums[l];
	}
}
