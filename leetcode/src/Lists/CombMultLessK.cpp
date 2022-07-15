int Ann(vector<int> nums, int i, double k) {
    cout << i << " " << k << " " << endl;
    // i denotes the init number while k is the rest target number
    if (nums[i] >= k) return 0;
    int n = nums.size();
    if (i == n - 1) return nums[i] < k;

    int temp = 1;
    for (int idx = i + 1; idx < n; idx++) {
        temp += Ann(nums, idx, k / nums[i]);
    }
    cout << "end" << i << " " << k << " " << temp << endl;

    return temp;
}

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int n = nums.size();
    int ans = 0;
    double ik = k;

    for (int i = 0; i < n; i++) {
        ans += Ann(nums, i, ik);
    }

    return ans;
}
