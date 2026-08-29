class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> dp;
    int f(vector<int>& arr, int i, int x) {
        if (x == 0)
            return 0;
        if (i == arr.size())
            return INT_MIN;

        if (dp[i][x] != INF)
            return dp[i][x];

        int not_take = f(arr, i + 1, x);

        int take = INT_MIN;
        if (arr[i] <= x) {
            int res = f(arr, i + 1, x - arr[i]);
            if (res != INT_MIN)
                take = 1 + res;
        }

        return dp[i][x] = max(take, not_take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        dp.assign(nums.size() + 1, vector<int>(target + 1,INF ));
        int ans = f(nums, 0, target);
        return (ans == INT_MIN) ? -1 : ans;
    }
};