class Solution {
public:
    /*

     we can do like store all frequency of chars in hash maps of 2 different
     strings in diff. hash maps

        and see if the chars of s1 and chars of s2 are same like there is no
     such character which is not present in both then we can simply concatinate
     the char whose char is distinct with that freq and whose chars having
     similar in both hash maps we can see the max freq out of it and concatinate
     and lastly add any character to the answer string whose freq = 1

        and if we have atleast one char that differs in both hash maps then do
     the above process and avoid the last step

        The above approach doesnt work because in this subsequence order
     matter's

        and We are very close to the intution dude FUCK

    */
    vector<vector<int>> dp;
    string shortestCommonSupersequence(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        dp.assign(n1, vector<int>(n2, 0));

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (s[i] == t[j]) {
                    dp[i][j] = 1 + ((i > 0 && j > 0) ? dp[i - 1][j - 1] : 0);
                } else {
                    dp[i][j] = max({((i - 1 >= 0) ? dp[i - 1][j] : 0),
                                    ((j - 1 >= 0) ? dp[i][j - 1] : 0)});
                }
            }
        }
        string ans = "";

        int i = n1 - 1;
        int j = n2 - 1;

        while (i >= 0 && j >= 0) {
            if (s[i] == t[j]) {
                ans += s[i];
                i--, j--;
            } else { // s1[i] != s2[j]
                if (i == 0) {
                    // s[0] is still needed, but t[j] is the
                    // character we choose from t
                    ans += t[j];
                    j--;
                } else if (j == 0) {
                    ans += s[i];
                    i--;
                } else {
                    if (dp[i - 1][j] > dp[i][j - 1]) {
                        ans += s[i];
                        i--;
                    } else {
                        ans += t[j];
                        j--;
                    }
                }
            }
        }

        while (i >= 0) {
            ans += s[i];
            i--;
        }
        while (j >= 0) {
            ans += t[j];
            j--;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};