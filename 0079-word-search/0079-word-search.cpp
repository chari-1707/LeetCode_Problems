class Solution {
public:
    bool f(int i, int j, vector<vector<char>>& arr, int k, string& pattern,vector<vector<bool>>& visited) {

        // base cases
        if (k == pattern.size())
            return true;

        if (i < 0 || i >= arr.size() || j < 0 || j >= arr[0].size())
            return false;

        if (visited[i][j] == true || arr[i][j] != pattern[k]) return false;

        visited[i][j] = true;

        bool ans = f(i, j - 1, arr, k + 1, pattern, visited) ||
                   f(i, j + 1, arr, k + 1, pattern, visited) ||
                   f(i - 1, j, arr, k + 1, pattern, visited) ||
                   f(i + 1, j, arr, k + 1, pattern, visited);

        // // either go left
        // p = f(i, j - 1, arr, k, pattern);

        // // go right
        // q = f(i, j + 1, arr, k, pattern);

        // // go up
        // r = f(i - 1, j, arr, k, pattern);

        // // go down
        // s = f(i + 1, j, arr, k, pattern);

        visited[i][j] = false;

        return ans;
    }

    bool exist(vector<vector<char>>& arr, string word) {
        bool ans = false;
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(f(i, j, arr, 0, word, visited)) return true;
            }
        }

        return ans;
    }
};