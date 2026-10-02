class Solution {
public:
    void helper(string s, vector<string>& ans, int no, int nc, int n) {
        if (no == n && nc == n) {
            ans.push_back(s);
            return;
        }
        if (no >= nc && no != n)
            helper(s + '(', ans, no + 1, nc, n);
        if (no > nc)
            helper(s + ')', ans, no, nc + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper("", ans, 0, 0, n);
        return ans;
    }
};