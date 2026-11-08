class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.size();

        int i = 0, j = 0, k = 0;

        while( i < n && j < n){
            if(s1[i] != s2[j]){
                string p = "";
                string q = "";
                while(s1[i] != s2[j]){
                    p += s1[i];
                    q += s2[j];
                    i++;
                    j++;
                }
                ans.push_back({p, q});
            }
            i++;
            j++;
        }

        return ans;

    }
};