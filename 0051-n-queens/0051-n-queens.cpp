class Solution {
public:
    /*
        Here, i -> rows
              j -> columns

    */

    bool canPlaceQueen(int row, int col, vector<string>& arr){
        int n = arr.size();
        bool flag = true;

        //column check
        for(int i = row - 1; i >= 0; i--){
            if(arr[i][col] != '.') flag = false;
        }

        //left diagonal check
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){ // contains two variables
            if(arr[i][j] != '.') flag = false;
        }

        //right diagonal check
        for(int i = row - 1, j = col + 1; i >= 0 && j < n ; i--, j++){ // contains two variables
            if(arr[i][j] != '.') flag = false;
        }

        return flag;
    }

    void f(int i, vector<string>& arr, vector<vector<string>>& ans) {

        if (i == arr.size()) {
            ans.push_back(arr);
            return;
        }

        for (int j = 0; j < arr.size(); j++) { // we try all possibilites j = 0 to n - 1
            if (canPlaceQueen(i, j, arr)) { 
                arr[i][j] = 'Q';
                f(i + 1, arr, ans); // function call
                arr[i][j] = '.'; // This is the step of backtracking revert it back
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> arr;
        arr.clear();
        arr.resize(n, string(n, '.'));

        f(0, arr, ans);

        return ans;
    }
};