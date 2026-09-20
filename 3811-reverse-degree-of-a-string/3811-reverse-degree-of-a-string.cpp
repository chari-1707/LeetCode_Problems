class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;


        for(int i = 0; i < s.length();i++){
            int x = i+ 1;
            int y = 26 - (s[i] - 'a');
            degree += (x * y);
        }

        return degree;
    }
};