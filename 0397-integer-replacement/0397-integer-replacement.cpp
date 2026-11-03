#define ll long long

class Solution {
public:
    unordered_map<ll, ll>dp;
    ll f(ll n){

        if(n == 1) return 0;

        if(dp.count(n)) return dp[n];

        ll x = 0, y = 0;
        if(n % 2 == 0) {
            return dp[n] = 1 + f(n / 2);
        }else{
            x = 1 + f(n + 1);
            y = 1 + f(n - 1);
        }

        return dp[n] = min({x, y});

    }
    int integerReplacement(int n) {
        // dp.assign(2147483648, -1);
        return (int)f(1LL * n);
    }
};