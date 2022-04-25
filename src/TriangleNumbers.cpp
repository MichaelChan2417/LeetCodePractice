// Find the valid constructed triangle numbers
// this is using the bisection method
int triangleNumberI(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0;

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l_sum = nums[i] + nums[j];

            int left = j + 1, right = n - 1;

            if (left == right) {
                res += l_sum > nums[left];
                continue;
            }

            while (left < right) {
                int mid = (left + right) / 2;
                if (nums[mid] >= l_sum) {
                    right = mid;
                }
                else {
                    left = mid + 1;
                }
            }
            res += left - j - 1 + (nums[left] < l_sum);
        }
    }

    return res;
}

// the following is using the double pointer
int triangleNumberII(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int res = 0;

    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i; j < n; j++) {
            while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                k++;
            }
            res += max(k - j, 0);
        }
    }
    return res;
}
