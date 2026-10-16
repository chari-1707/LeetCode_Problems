class Solution {
public:
    bool EveryCellVisited(vector<vector<int>>& arr,
                          vector<vector<bool>>& visited) {
        for (int x = 0; x < visited.size(); x++) {
            for (int y = 0; y < visited[0].size(); y++) {
                if (arr[x][y] == -1)
                    continue;
                if (!visited[x][y])
                    return false;
            }
        }
        return true;
    }

    // unordered_set<pair<int,int>>visited;
    int f(int i, int j, vector<vector<int>>& arr,
          vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size()) return 0;

        if (visited[i][j] || arr[i][j] == -1)  return 0;

        if (arr[i][j] == 2) {
            visited[i][j] = true;
            bool valid = EveryCellVisited(arr, visited);
            visited[i][j] = false;
            return valid ? 1 : 0;
        }

        visited[i][j] = 1;

        int x = f(i + 1, j, arr, visited) + f(i - 1, j, arr, visited) +
                f(i, j + 1, arr, visited) + f(i, j - 1, arr, visited);

        visited[i][j] = 0;

        return x;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int i = 0, j = 0;

        vector<vector<bool>> visited;

        int m = grid.size();
        int n = grid[0].size();

        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    break;
                }
            }
            if (j < grid[0].size())
                break;
        }

        // cout << i << " " << j << endl;

        visited.assign(m, vector<bool>(n, false));

        return f(i, j, grid, visited);
    }
};