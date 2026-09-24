class Solution {
public:
    void combination(vector<int> &v, vector<int> arr, int target, int idx,
vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        if (target < 0)
            return;

        for (int i = idx; i < arr.size(); i++) {
            v.push_back(arr[i]);
            combination(v, arr, target - arr[i], i, ans);
            v.pop_back();  
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        combination(v, candidates, target, 0, ans);
        return ans;
    }
};