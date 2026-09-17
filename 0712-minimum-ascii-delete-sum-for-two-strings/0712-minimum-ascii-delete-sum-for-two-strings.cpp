class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j, string& s, string& t) {

        if (i == s.length()) {
            int p = 0;
            for (int k = j; k < t.length(); k++) {
                p += (int)t[k];
            }
            return p;
        }

        if (j == t.length()) {
            int q = 0;
            for (int k = i; k < s.length(); k++) {
                q += (int)s[k];
            }

            return q;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = f(i + 1, j + 1, s, t);
        }

        int x = (int)s[i] + f(i + 1, j, s, t);
        int y = (int)t[j] + f(i, j + 1, s, t);

        return dp[i][j] = min({x, y});
    }

    int fbu(string& s, string& t) {
        int m = s.length();
        int n = t.length();
        dp.assign(m + 1, vector<int>(n + 1, 0));

        // filling the base cases

        for (int j = 0; j < n; j++) {
            int p = 0;
            for (int k = j; k < t.length(); k++) {
                p += (int)t[k];
            }
            dp[m][j] = p;
        }

        for (int i = 0; i < m; i++) {
            int q = 0;
            for (int k = i; k < s.length(); k++) {
                q += (int)s[k];
            }
            dp[i][n] = q;
        }

        dp[m][n] = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    int x = (int)s[i] + dp[i + 1][j];
                    int y = (int)t[j] + dp[i][j + 1];

                    dp[i][j] = min({x, y});
                }
            }
        }


        return dp[0][0];
    }

    int minimumDeleteSum(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp.assign(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, s, t);
    }
};