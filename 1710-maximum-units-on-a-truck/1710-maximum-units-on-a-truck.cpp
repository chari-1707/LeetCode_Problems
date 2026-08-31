class Solution {
public:

    /**
        1  3
        2  2
        3  1   

        TruckSize = 4 maximum units= ?


        



    **/
    static bool cmp(vector<int>&a, vector<int>&b){
        return (a[1] >= b[1]);
    }

    int maximumUnits(vector<vector<int>>& arr, int x) {
        sort(begin(arr),end(arr),cmp);

        // for(auto ele : arr){
        //     for(auto p : ele){
        //         cout << p <<" ";
        //     }
        //     cout << endl;
        // }
        int ans = 0;

        for(int i = 0;i<arr.size();i++){
            if(x == 0) break;
            if(arr[i][0] <= x) {
                ans +=(arr[i][1] * arr[i][0]);
                x -= arr[i][0];
            }else{ 
                ans += (x * arr[i][1]);
                x -= x;
            }
        }
        return ans;
    }
};