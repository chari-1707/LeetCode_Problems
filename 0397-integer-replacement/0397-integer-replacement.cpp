#define ll long long

class Solution {
public:
    ll f(ll n){

        if(n == 1) return 0;

        ll x = 0, y = 0;
        if(n % 2 == 0) {
            return 1 + f(n / 2);
        }else{
            x = 1 + f(n + 1);
            y = 1 + f(n - 1);
        }

        return min({x, y});

    }
    int integerReplacement(int n) {
        return (int)f(1LL * n);
    }
};