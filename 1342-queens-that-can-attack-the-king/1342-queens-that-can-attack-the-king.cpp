
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        vector<vector<int>> ans;

        vector<vector<int>>board(8, vector<int>(8, 0));

        for(auto x: queens){
            board[x[0]][x[1]] = 1;
        }

        board[king[0]][king[1]] = 2;
        
        for(auto ele : queens){

            int i = ele[0], j = ele[1];

            //we need to explore in queen movable position's

            //right
            for(int k = j + 1; k < 8; k++){

                int pos = board[i][k];

                //check for any queen is obstacking you
                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({i, j});
                    break;
                }
            }


            //left 
            for(int k = j - 1; k >= 0; k--){
                int pos = board[i][k];

                //check for any queen is obstacking you
                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({i, j});
                    break;
                }
            }

            // down
            for(int k = i + 1; k < 8; k++){
                 int pos = board[k][j];

                //check for any queen is obstacking you
                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({i, j});
                    break;
                }
            }
            //up
            for(int k = i - 1; k >= 0; k--){
                 int pos = board[k][j];

                //check for any queen is obstacking you
                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({i, j});
                    break;
                }
            }

            //diagonal up
            i = ele[0], j = ele[1];

            while(i > 0 && j > 0){
                i--;
                j--;

                int pos = board[i][j];

                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({ele[0], ele[1]});
                    break;
                }

                
            }

            i = ele[0], j = ele[1];
            //diagonal down
            while(i < 7 && j < 7){

                i++;
                j++;

                int pos = board[i][j];

                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({ele[0], ele[1]});
                    break;
                }

            }

            i = ele[0], j = ele[1];
            //diagonal right
            while(i > 0 && j < 7){

                i--;
                j++;

                int pos = board[i][j];

                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({ele[0], ele[1]});
                    break;
                }

            }

            i = ele[0], j = ele[1];
            //diagonal left
            while(i < 7 && j > 0){

                i++;
                j--;

                int pos = board[i][j];

                if(pos == 1) break;

                if(pos == 2){
                    ans.push_back({ele[0], ele[1]});
                    break;
                }

            }
        }

        return ans;


    }
};
