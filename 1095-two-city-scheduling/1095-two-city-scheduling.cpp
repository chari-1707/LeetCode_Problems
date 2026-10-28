class Solution {
public:
    vector<vector<vector<int>>> dp;
    int f(int i, int x, int y, vector<vector<int>>& arr){
        
        if(x == 0 && y == 0 || (i >= arr.size())) return 0;

        if(x == 0){
            int sum = 0;
            while(i != arr.size()){
                sum += (arr[i][1]);
                i ++;
            }
            return sum;
        }

        if(y == 0){
            int sum = 0;
            while(i != arr.size()){
                sum += (arr[i][0]);
                i ++;
            }
            return sum;
        }

        if(dp[i][x][y] != -1) return dp[i][x][y];

        int p = arr[i][0] + f(i + 1, x - 1, y, arr);

        int q = arr[i][1] + f(i + 1, x, y - 1, arr);

        return dp[i][x][y] = min({p, q});
    }

    int twoCitySchedCost(vector<vector<int>>& arr) {
        int n = arr.size();

        int x , y;
        x = y = n / 2;

        dp.resize(n + 1, vector<vector<int>> (x + 1, vector<int> (y+ 1, -1)));

        return f(0, x, y, arr);
        
    }
};