class Solution {
public:
    vector<vector<int>> dp;
    int f(string& s1, string& s2, int i, int j) {
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + f(s1, s2, i - 1, j - 1);
        } else {
            return dp[i][j] = max({f(s1, s2, i - 1, j), f(s1, s2, i, j - 1)});
        }
    }
    int minDistance(string a, string b) {
        int m = a.size();
        int n = b.size();
        dp.assign(m, vector<int>(n, -1));
        int lcs = f(a, b, m - 1, n - 1);

        int del = m - lcs;
        int ins = n - lcs;

        return del + ins;
    }
};