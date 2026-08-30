class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX, mx = INT_MIN;
        int mnIdx = -1, mxIdx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] > mx) {
                mx = nums[i];
                mxIdx = i;
            }
            if (nums[i] < mn) {
                mn = nums[i];
                mnIdx = i;
            }
        }

        if (mnIdx == mxIdx) {
            return min(mnIdx + 1, n - mnIdx);
        } else if (mnIdx <= n / 2 && mxIdx <= n / 2) {
            return max(mnIdx, mxIdx) + 1;
        } else if (mnIdx >= n / 2 && mxIdx >= n / 2) {
            return max(n - mnIdx, n - mxIdx);
        } else{ 
            int x = max(mnIdx, mxIdx) + 1;
        int y = max(n - mnIdx, n - mxIdx);
        int z = min({mnIdx + 1 + n - mxIdx,mxIdx + 1 + n - mnIdx});
        return min({x,y,z});
        }

        // int x = max(mnIdx, mxIdx) + 1;
        // int y = max(n - mnIdx, n - mxIdx);
        // int z = min({mnIdx + 1 + n - mxIdx,mxIdx + 1 + n - mnIdx});
        // return min({x,y,z});
    }
};