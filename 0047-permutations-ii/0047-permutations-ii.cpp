class Solution {
public:
    void f(vector<int>& arr, int i, vector<vector<int>>& finalAns) {
        if(i == arr.size() - 1){
            finalAns.push_back(arr);
            return;
        }

        unordered_set<int>s;
        for(int idx = i; idx < arr.size(); idx++){
            if(s.count(arr[idx])) continue;

            s.insert(arr[idx]);
            swap(arr[i],arr[idx]);
            f(arr, i+1 ,finalAns);
            swap(arr[i],arr[idx]);
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        f(arr, 0, ans);

        return ans;
    }
};