class Solution {
public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();

        int noOfDel = 0;

        for (int i = 0; i < n; i++) {

            if ((i + 1 < n) && ((arr[i] ^ arr[i + 1]) == 0)) {
                // cout << i << " ";
                noOfDel = noOfDel + 1;
            } else {
                continue;
            }
        }

        return noOfDel;
    }
};