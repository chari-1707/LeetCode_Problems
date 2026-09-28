class Solution {
public:
    #define ll long long
    const int MOD = 1e9 + 7;
    vector<vector<vector<ll>>> dp;
    ll f(int i, int j, int k, int m, int n){

        if(i < 0 || j < 0 || i >= m || j >= n) return 1; // out of bound so we found one

        //base cases
        if(k == 0) return 0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        //This will give me the no.of ways if i move left
        int left = f(i, j - 1, k - 1, m, n);

        //This will give me the no.of ways if i move right
        int right = f(i, j + 1, k - 1, m, n);

        //This will give me the no.of ways if i move up
        int up = f(i - 1, j, k - 1, m, n);

        //This will give me the no.of ways if i move down
        int down = f(i + 1, j, k - 1, m, n);

        return dp[i][j][k] = (1LL * left + right + up + down) % MOD;

    }

    int findPaths(int m, int n, int k, int i, int j) {
        dp.clear();
        dp.resize(m + 1, vector<vector<ll>> (n + 1, vector<ll> (k + 1, -1)));

        return (int)f(i, j, k, m, n) % MOD;
    }
};