class Solution {
public:
    /**

        we need to find the palindromic subsequence

        bbbab





    **/
    vector<vector<int>> dp;
    int f(int i, int j, string& s) {

        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if ((s[i] == s[j]) && (i - j) != 0) {
            return dp[i][j] = 2 + f(i + 1, j - 1, s);
        } else {
            return dp[i][j] = max({f(i + 1, j, s), f(i, j - 1, s)});
        }
    }

    int longestPalindromeSubseq(string s) {
        int n = s.length();
        dp.assign(n + 1, vector<int>(n + 1, -1));
        return f(0, n - 1, s);
    }
};