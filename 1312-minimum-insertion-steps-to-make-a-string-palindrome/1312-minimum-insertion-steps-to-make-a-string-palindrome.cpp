class Solution {
public:
    /**





    **/
    vector<vector<int>> dp;
    int f(int i, int j, string& s) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = f(i + 1, j - 1, s);
        else {
            return dp[i][j] = 1 + min({f(i + 1, j, s), f(i, j - 1, s)});
        }
    }

    int fbu(string& s,int n) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                     dp[i][j] = dp[i + 1][j - 1];
                else {
                    dp[i][j] = 1 + min({dp[i + 1][j], dp[i][j - 1]});
                }
            }
        }
        return dp[0][n - 1];
    }

    int minInsertions(string s) {
        int n = s.length();
        // dp.assign(n + 1, vector<int>(n + 1, -1));
        // return f(0, n - 1, s);
        return fbu(s , n);
    }
};