class Solution {
public:

    bool canPlaceQueen(int row, int col, vector<string>& arr){
        int n = arr.size();
        // bool flag = true;

        //column check
        for(int i = row - 1; i >= 0; i--){
            if(arr[i][col] != '.') return false;
        }

        //left diagonal check
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){ // contains two variables
            if(arr[i][j] != '.') return false;
        }

        //right diagonal check
        for(int i = row - 1, j = col + 1; i >= 0 && j < n ; i--, j++){ // contains two variables
            if(arr[i][j] != '.') return false;
        }

        return true;
    }

    void f(int i, vector<string>& arr, int& ans) {

        if (i == arr.size()) {
            ans = ans + 1;
        }

        for (int j = 0; j < arr.size(); j++) { // we try all possibilites j = 0 to n - 1
            if (canPlaceQueen(i, j, arr)) { 
                arr[i][j] = 'Q';
                f(i + 1, arr, ans); // function call
                arr[i][j] = '.'; // This is the step of backtracking revert it back
            }
        }

    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> arr;
        arr.clear();
        arr.resize(n, string(n, '.'));

        f(0, arr, ans);

        return ans;
    }
};