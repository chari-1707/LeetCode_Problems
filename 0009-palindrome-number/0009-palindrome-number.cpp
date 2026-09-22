class Solution {
public:
    long long reverse(long long n){
        long long ans = 0;
        while(n > 0){
            ans += (n % 10);
            ans *= 10;
            n /= 10;
        }
        return ans/10;
    }


    bool isPalindrome(int x) {
        long long y = reverse(x);
        return (y == (long long)x);
    }
};