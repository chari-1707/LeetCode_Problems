class Solution {
public:
    void f(vector<int>& arr, int i,vector<vector<int>>& finalAns) {
        if(i == arr.size() - 1){
            finalAns.push_back(arr);
            return;
        }

        for(int idx = i; idx < arr.size(); idx++){
            swap(arr[i],arr[idx]);
            f(arr, i+1 ,finalAns);
            swap(arr[i],arr[idx]);
        }

        return;
    }

    vector<vector<int>> permute(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        f(arr, 0, ans);

        return ans;
    }
};