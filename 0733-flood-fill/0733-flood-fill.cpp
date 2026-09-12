class Solution {
public:
    unordered_set<int> visited;
    void f(vector<vector<int>>& arr, int i, int j, int x, int target) {

        // base case on out of bound
        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size()) return;

        // if already visited cell then return
        if(visited.count(arr[i][j])) return;

        //if not visited then check the condition and update if satisfies
        if (!visited.count(arr[i][j])) {
            if (arr[i][j] == x) arr[i][j] = target;
            else {
                visited.insert(arr[i][j]);
                return;
            }
        }

        // mark it as visited
        visited.insert(arr[i][j]);


        int p = -1, q = -1, r = -1, s = -1;
        if (i > 0)
            p = arr[i - 1][j];
        if (i < arr.size() - 1)
            q = arr[i + 1][j];
        if (j > 0)
            r = arr[i][j - 1];
        if (j < arr[0].size() - 1)
            s = arr[i][j + 1];

        if (p != x && q != x && r != x && s != x) return;

        f(arr, i - 1, j, x, target);
        f(arr, i + 1, j, x, target);
        f(arr, i, j - 1, x, target);
        f(arr, i, j + 1, x, target);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        f(image, sr, sc, image[sr][sc], color);
        return image;
    }
};