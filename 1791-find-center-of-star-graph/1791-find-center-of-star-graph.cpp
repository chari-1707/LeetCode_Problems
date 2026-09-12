class Solution {
public:
    /**
        TARGET: we have to find the center of the star graph

        observations:

        1. may be we can find the common value in the edges array
          -but the question is can there be a duplicate nodes with same values
            i guess not for atleast this star graph because if duplicates we may
    not able to make start graph


        2. How tf we do it then :
                since there is only 2 cols






    **/

    int findCenter(vector<vector<int>>& arr) {
        int cnt1 = 0, cnt2 = 0;
        int n = arr.size();
        int x = arr[0][0];
        int y = arr[0][1];

        for (int i = 1; i < n; i++) {
            if(arr[i][0] == x) cnt1++;
            else if(arr[i][0] == y) cnt2++;
            else if(arr[i][1] == x) cnt1++;
            else if(arr[i][1] == y) cnt2++;
        }

        if(cnt1 == n - 1) return x;
        if(cnt2 == n - 1) return y;

        cout<<cnt1<<" "<<cnt2<<endl;

        return -1;
    }
};