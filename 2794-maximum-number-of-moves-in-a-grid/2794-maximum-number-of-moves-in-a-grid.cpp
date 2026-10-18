class Solution {
public:

    vector<vector<int>> dp;
    int f(int i, int j, int m, int n, vector<vector<int>>& arr) {

        if(dp[i][j] != -1) return dp[i][j];

        int x, y, z;
        x = y = z = 0;

        if (i - 1 >= 0 && j + 1 < n && arr[i - 1][j + 1] > arr[i][j]) {
            x = 1 + f(i - 1, j + 1, m, n, arr);
        }if (i < m && j + 1 < n && arr[i][j + 1] > arr[i][j]) {
            y = 1 + f(i, j + 1, m, n, arr);
        }if (i + 1 < m && j + 1 < n && arr[i + 1][j + 1] > arr[i][j]) {
            z = 1 + f(i + 1, j + 1, m, n, arr);
        }

        return dp[i][j] = max({x, y, z});
    }

    int maxMoves(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        dp.assign(m+1, vector<int>(n+1 , -1));

        int maxi = INT_MIN;
        for (int i = 0; i < m; i++) {
            int x = f(i, 0, m, n, arr);
            maxi = max(maxi, x);
        }

        return maxi;
    }
};