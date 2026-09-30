class Solution {
public:

    bool isSafe(int r, int c, int val, vector<vector<char>>& grid){

        //check for the rows and columns
        for(int i = 1; i <= 9; i++){
            if(grid[r][i - 1] - '0' == val || grid[i - 1][c] - '0' == val) return false;
        }


        //Check for the 3X3 boxes depending upon where (i, j) lies

        int row = (r / 3) * 3; //with this we get top left of the box 
        int col = (c / 3) * 3; //same as above

        for(int i = row ; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                if(grid[i][j] - '0' == val) return false;
            }
        }

        return true;
    }


    bool f(int r, int c, vector<vector<char>>& grid ){

        if(r == 9) return true; // means we filled entire grid successfully
        if(c == 9) return f(r + 1, 0, grid);
        if(grid[r][c] != '.') return f(r, c + 1, grid);

        for(int val = 1; val <= 9; val++){

            if(isSafe(r, c, val, grid)){

                grid[r][c] = '0' + val;

                bool result = f(r, c + 1, grid);
                if(result) return true;

                grid[r][c] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        f(0, 0, board);
    }
};