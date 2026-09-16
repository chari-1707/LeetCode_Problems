class Solution {
public:
    /*

    I have got the FUCKING Algorithm!!!!! but dont know how to code LET'S TRY

    1. we keep 2 pointers in both strings and move forward if both chats are
    equal
    2. if they are not equal we jump to next char in s string but j remains same
    3. if j reaches the end means we found one occur. or subsequence of s which
    == t immdiately we make count++ and what comes next is imp part

    4. since we got the full string we see if the last char of t is occurs in
       i+1 to s.length() - 1 if occurs we make count++ because we have prefix of
    remaining

    5. if we reach till the end of s string then again we start searching for
    j-2 to t.length() from the i - 1 to s.length() here i is the next idx at
    which we found the 1st occurence of t in s like that we do till j < 0 and
    finally we return answer like that .....

    */

    vector< vector<int> > dp;
    int f(int i, int j, string& s, string& t) {
        if (j == t.length())
            return 1;

        if (i == s.length())
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] =  f(i + 1, j + 1, s, t) + f(i + 1, j, s, t);
        else
            return dp[i][j] =  f(i + 1, j, s, t);

        return -1;
    }

    int numDistinct(string s, string t) { 
        dp.assign(s.length() + 1, vector<int> (t.length() + 1 , -1));

        return f(0, 0, s, t); 
        
    }
};