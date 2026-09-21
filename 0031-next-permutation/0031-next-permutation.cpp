class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // idx == -1 means it is at its last permutation so we need to return
        // 1st permutation
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        reverse(nums.begin() + idx + 1, nums.end());
        int j = -1;
        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }
        swap(nums[idx], nums[j]);

        return;
    }
};