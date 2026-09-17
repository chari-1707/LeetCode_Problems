class Solution {
public:
    /*


    we have to make s as t :
        we can insert , delete , replace a character
        the only difference between insert, delete question and this question is
    there we do have only insert and delete in which we see if characters dont
    match we either delete the char or insert it so that they might be equal in
    the future

        since here, we can replace we do another extra call and remaining as it
    is and we take minimum .

    */

    vector<vector<int>> dp;
    int f(int i, int j, string& s, string& t) {

        if (i == s.length()) return (t.length() - j);
        if (j == t.length()) return (s.length() - i);

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return f(i + 1, j + 1, s, t);
        }

        int x = 1 + f(i + 1, j, s, t);
        int y = 1 + f(i, j + 1, s, t);
        int z = 1 + f(i + 1, j + 1, s, t);

        return dp[i][j] = min({x, y, z});
    }

    int minDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        dp.clear();
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return f(0, 0, s, t);
    }
};