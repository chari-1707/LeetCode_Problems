class Solution {
public:
/*

          aacaba





*/
    int numSplits(string s) {

        int ans = 0;
        unordered_map<int, int> s1;
        unordered_map<int, int> s2;

        for (auto& ele : s)
            s2[(ele)]++;

        for (int i = 0; i < s.length(); i++) {

            s1[s[i]]++;
            s2[s[i]]--;

            if(s2[s[i]] == 0) s2.erase(s[i]);

            // bool flag = true;
            // for (auto ele : s1) {
            //     if(s2.find(ele.first) != s2.end()){
            //         flag = false;
            //     }
            // }

            // The only thing is we need to write the logic for how we know that
            // in both of the maps having disticnt elements and that too with
            // low Time C Complexity that's it done

            if (s1.size() == s2.size()) { // Whether distinct on both left and right
                ans = ans + 1;
            }
        }

        return ans;
    }
};