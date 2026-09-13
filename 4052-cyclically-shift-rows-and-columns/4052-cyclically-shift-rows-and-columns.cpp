class Solution {
public:
    // 1 2 3 4 k = 2
    // 2 1 4 3
    // 3 4 1 2
    void reverse1(int col, int i, int j, vector<vector<int>>& arr) {
        while (i < j) {
            swap(arr[i][col], arr[j][col]);
            i++;
            j--;
        }
    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& arr,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {

        for (int i = 0; i < n; i++) {
            int k = rowShift[i];
            reverse(arr[i].begin(), arr[i].begin() + k);
            reverse(arr[i].begin() + k, arr[i].end());
            reverse(begin(arr[i]), end(arr[i]));
        }

        for (int j = 0; j < n; j++) {
            int k = colShift[j];
            reverse1(j, 0, k - 1, arr);
            reverse1(j, k, n - 1, arr);
            reverse1(j, 0, n - 1, arr);
        }

        return arr;
    }
};