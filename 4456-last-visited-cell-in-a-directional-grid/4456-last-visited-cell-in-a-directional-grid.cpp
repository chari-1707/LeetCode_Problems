class Solution {
public:
    vector<vector<bool>> visited;
    void f(int i, int j, vector<vector<char>>& arr, vector<int>& ans){

        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size() || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        ans[0] = i;
        ans[1] = j;

        if(arr[i][j] == 'R'){
            f(i, j + 1, arr, ans);
        }else if(arr[i][j] == 'L'){
              f(i, j - 1, arr, ans);
        }else if(arr[i][j] == 'U'){
              f(i - 1, j, arr, ans);
        }else if(arr[i][j] == 'D'){
              f(i + 1, j, arr, ans);
        }
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<int> ans(2, 0);
        visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
        f(0, 0, grid, ans);
        return ans;
    }
};