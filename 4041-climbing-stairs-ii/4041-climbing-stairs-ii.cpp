class Solution {
public:
    vector<int> dp;
    int f(int i, vector<int>& c, int n) {

        if (i == n)
            return 0;
        if (i == n - 1)
            return (1 + c[i]);

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = min({
                   c[i] + 1 + f(i + 1, c, n),
                   (i + 2 <= n) ? c[i + 1] + 4 + f(i + 2, c, n) : INT_MAX,
                   (i + 3 <= n) ? c[i + 2] + 9 + f(i + 3, c, n) : INT_MAX,
               });
    }

    int fbu(vector<int>& c, int n) {
        dp[n] = 0;
        dp[n - 1] = 1 + c[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dp[i] = min({
                c[i] + 1 + dp[i + 1],
                (i + 2 <= n) ? c[i + 1] + 4 + dp[i + 2] : INT_MAX,
                (i + 3 <= n) ? c[i + 2] + 9 + dp[i + 3] : INT_MAX,
            });
        }
        return dp[0];
    }

    int climbStairs(int n, vector<int>& costs) {
        dp.resize(n + 1, -1);
        // return f(0, costs, n);
        return fbu(costs, n);
    }
};