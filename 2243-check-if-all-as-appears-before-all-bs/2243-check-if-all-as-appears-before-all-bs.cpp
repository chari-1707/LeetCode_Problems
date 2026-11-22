class Solution {
public:
    bool checkString(string s) {
        unordered_map<char,int>m;
        for(auto ele : s) m[ele]++;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                m['a']--;
            }
            if(m['a'] == 0) m.erase('a');

            if(s[i] == 'b'){
                if(m['a'] != 0) return false;
            }
        }

        return true;
    }
};