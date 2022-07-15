#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <typeinfo>

using namespace std;

// Remove Dup from Sorted Array
int RemoveFromDup(vector<int>& array) {
	// whether empty array
	if (array.empty()) {
		return 0;
	}

	int length = array.size();
	int index = 0;
	for (int i = 1; i < array.size(); i++) {
		if (array[i] != array[index]) {
			array[++index] = array[i];
		}
	}
	int count = 0;
	while (count < length-index-1) {
		array.pop_back();
		count++;
	}
	return index + 1;
}


// Remove Dup from Sorted Array but allow the 2 dup 
int RemoveDup2(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}

	int length = nums.size();
	int index = 0;
	int tempcount = 1;
	for (int i = 1; i < length; i++) {
		// first if we read the duplicated int, we should add the count first and if the count <=2 keeps
		// its place. but if >2 just continue
		if (nums[i] == nums[index]) {
			tempcount++;
			if (tempcount <= 2) {
				nums[++index] = nums[i];
			}
			else {
				continue;
			}
		}
		// now we read a new int
		else {
			nums[++index] = nums[i];
			tempcount = 1;
		}
	}
	int count = 0;
	while (count < length - index - 1) {
		nums.pop_back();
		count++;
	}

	return index + 1;
}


// Search in Rotated Sorted Array
// like 0 1 2 3 4 5 6 might be 3 4 5 6 0 1 2
int SearchInRSA(vector<int>& nums, int x) {
	int left = 0;
	int right = nums.size();
	while (left != right) {
		int mid = left + (right - left) / 2;
		// if the mid is the target
		if (nums[mid] == x) {
			return mid;
		}

		// now its the correct order
		if (nums[mid] > nums[left]) {
			if (x >= nums[left] && x < nums[mid]) {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		else {
			if (x > nums[mid] && x < nums[left]) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
	}
	return -1;
}


// find the k-smallest number in two sorted array
int find_kth(vector<int>& A, int As, vector<int>& B, int Bs, int k) {
	// firstly always let the A be the shorter length one;
	int rest_A = A.size() - As;
	int rest_B = B.size() - Bs;
	if (rest_A > rest_B) return find_kth(B, Bs, A, As, k);
	if (rest_A == 1) return B[Bs + k-1];
	if (k == 1) return min(B[Bs], A[As]);

	int ia = min(k/2,rest_A-1);
	int ib = k - ia;

	if (A[As + ia - 1] > B[Bs + ib - 1]) {
		return find_kth(A, As, B, Bs + ib, k - ib);
	}
	else if (A[As + ia - 1] < B[Bs + ib - 1]) {
		return find_kth(A, As + ia, B, Bs, k - ia);
	}
	else {
		return A[As + ia - 1];
	}
	
}


// Longest Consecutive Sequence
int LongestConsectiveSeq(const vector<int>& A) {
	unordered_map<int, bool> used;
	for (auto i : A) used[i] = false;

	int longest = 0;
	for (auto i : A) {
		if (used[i]) continue;
		int temp = 1;
		used[i] = true;
		for (int j = i + 1; used.find(j) != used.end(); j++) {
			used[j] = true;
			temp++;
		}

		for (int j = i - 1; used.find(j) != used.end(); j--) {
			used[j] = true;
			temp++;
		}

		longest = max(longest, temp);
	}

	return longest;
}


// Two Sum
vector<int> FindTwoSum(vector<int>& nums, int target) {
	unordered_map<int, int> match;
	vector<int> ans;

	for (int i = 0; i < nums.size(); i++) {
		match[nums[i]] = i;
	}

	for (auto i : nums) {
		if (match.find(target - i) != match.end()) {
			ans.push_back(match[i]);
			ans.push_back(match[target - i]);
			return ans;
		}
	}
	ans.push_back(-1);
	ans.push_back(-1);
	return ans;
}


// 3Sum 定首 然后jk两边逼近剩余的（sorted）
vector<vector<int> > ThreeSum(vector<int>& sets) {
	vector<vector<int> >result;
	if (sets.size() < 3) return result;

	const int target = 0;
	sort(sets.begin(), sets.end());

	auto last = sets.end();
	for (auto i = sets.begin(); i < last - 2; i++) {
		auto j = i + 1;
		// if we have the same values; just continue
		if (i > sets.begin() && *i == *(i - 1)) continue;
		auto k = last - 1;

		while (j < k) {
			if (*i + *j + *k < target) {
				j++;
				// if the j is repetitive then just continue
				while (*j == *(j - 1) && j < k) j++;
			}
			else if (*i + *j + *k > target) {
				k--;
				while (*k == *(k + 1) && j < k) k--;
			}
			else {
				result.push_back({ *i,*j,*k });
				j++;
				k--;
				while (*j == *(j - 1) && j < k && *k == *(k + 1)) j++;
			}
		}
	}
	return result;
}


// Trapping Rain water
int TrapRain(vector<int>& nums) {
	int length = nums.size();
	vector<int> left_tr(length, 0);
	vector<int> right_tr(length, 0);
	int temp = 0;

	for (int i = 0; i < length; i++) {
		if (nums[i] > temp) {
			temp = nums[i];
		}
		left_tr[i] = temp;
	}

	temp = 0;
	for (int i = length - 1; i >= 0; i--) {
		if (nums[i] > temp) {
			temp = nums[i];
		}
		right_tr[i] = temp;
	}

	int contain = 0;
	for (int i = 0; i < length; i++) {
		contain += min(left_tr[i], right_tr[i]) - nums[i];
	}
	return contain;
}


// Rotate the image 90 degrees to right
void RotateRight(vector<vector<int> >& image) {
	const int n = image.size();

	// first diagonal rotate
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap(image[i][j], image[n - 1 - j][n - 1 - i]);
		}
	}

	// second horizontal rotate
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			swap(image[i][j], image[n - 1 - i][j]);
		}
	}
}


// Fibonacci or climb the stair
int ClimbStair(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	
	int temp1 = 1;
	int temp2 = 2;
	for (int i = 2; i < n; i++) {
		temp1 = temp1 + temp2;
		swap(temp1, temp2);
	}
	return temp2;
}


// Can Complete the Circuit
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int sum = 0;
	int total = 0;
	int pointer = -1;
	for (int i = 0; i < gas.size(); i++) {
		sum += gas[i] - cost[i];
		total += gas[i] - cost[i];

		if (sum < 0) {
			pointer = i;
			sum = 0;
		}
	}
	int ans = (total < 0) ? -1 : pointer+1;
	return ans;
}


// Prepare the candy
int candy(vector<int>& child) {
	// 直接两边扫描 比原来的大就加1 base不会变的
	int ans = 0;
	int length = child.size();
	int inc = 1;
	vector<int> temphold(length, 1);
	for (int i = 1; i < length; i++) {
		if (child[i] > child[i - 1]) {
			inc++;
			temphold[i] = inc;
		}
		else {
			inc = 1;
		}
	}
	inc = 1;
	for (int i = length - 2; i > -1; i--) {
		if (child[i] > child[i + 1]) {
			inc++;
			if (inc > temphold[i]) {
				temphold[i] = inc;
			}
		}
		else {
			inc = 1;
		}
	}
	for (int i = 0; i < length; i++) {
		ans += temphold[i];
		cout << temphold[i] << endl;
	}
	return ans;
	
}


// Find the Single number, each other number exist twice
// Using the XOR
int SingleOne(vector<int>& nums) {
	int ans = 0;
	for (int i : nums) {
		ans ^= i;
	}
	return ans;
}


// Find the Single Number, each other exist 3 times;
// A problem of bit-calculation
int SingleOneII(vector<int>& nums) {
	int W = sizeof(int) * 8;
	vector<int> count(W, 0);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < W; j++) {
			count[j] += (nums[i] >> j) & 1;
			count[j] = count[j] % 3;
		}
	}
	int ans = 0;
	for (int j = 0; j < W; j++) {
		ans += (count[j] << j);
	}
	return ans;
}
