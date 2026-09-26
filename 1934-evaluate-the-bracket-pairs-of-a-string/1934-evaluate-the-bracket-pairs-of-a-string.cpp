class Solution {
public:
    /*

    s = "(name)is(age)yearsold" knowledge = [ ["name","bob"] , ["age","two"] ]





    */

    // struct PairHash {
    //     size_t operator()(const pair<int, int>& p) const {
    //         return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    //     }
    // };

    // unordered_set<pair<string, string>, PairHash> words;

    unordered_map<string,string>words;

    string evaluate(string s, vector<vector<string>>& arr) {
        string ans = "";

        int m = arr.size();
        int n = s.size();

        for (int i = 0; i < m; i++) {
            words[arr[i][0]] = arr[i][1];
        }

        int i = 0;
        while (i < n) {
            if (s[i] == '(') {

                // int p = i; // start of the bracket

                if (i < n)
                    i = i + 1;
                string temp = "";

                while (s[i] != ')') { // finding the word
                    temp += s[i];
                    i++;
                }

                // int q = i; // end of the bracket


                if(words.find(temp) != words.end()){
                    ans += (words[temp]);
                    // words.erase(temp);
                }else{
                    ans += '?';
                }

            } else {
                ans += s[i];
            }

            i++;
        }

        return ans;
    }
};