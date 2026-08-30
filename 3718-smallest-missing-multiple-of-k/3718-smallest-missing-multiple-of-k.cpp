class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (auto ele : nums)
            s.insert(ele);

        int x = 1;
        int p = k;
        while (true) {
            if (s.find(p) != s.end()) {
                x = x + 1;
                p = (k * x);
            } else
                return p;
        }

    }
};