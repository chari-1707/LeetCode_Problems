class Solution {
public:
    unordered_set<int> visited;
    void bfs(vector<vector<int>>& arr) {
        queue<vector<int>> q;
        visited.clear();
        visited.insert(0);
        q.push(arr[0]);

        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            for (auto ele : v) {
                if (!visited.count(ele)) {
                    visited.insert(ele);
                    q.push(arr[ele]);
                }
            }
        }
    }
    void dfs(int curr, vector<vector<int>>& arr){

        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bfs(rooms);
        return (rooms.size() == visited.size());
    }
};