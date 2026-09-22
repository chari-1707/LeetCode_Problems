class Solution {
public:
    /*

        2,5,1,2,5

        10,5,2,1,5,2
    */
    vector<vector<int>>dp;
    int f(int i, int j, vector<int>& nums1, vector<int>& nums2) {

        if(i == nums1.size() || j == nums2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if (nums1[i] == nums2[j]) {
            return dp[i][j] =  1 + f(i + 1, j + 1, nums1, nums2);
        } else {
            return dp[i][j] =  max({f(i + 1, j, nums1, nums2), f(i, j + 1, nums1, nums2)});
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        dp.clear();
        dp.assign(m+1, vector<int>(n+1,-1));
        return f(0, 0, nums1, nums2);
    }
};