class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &ele: nums) if(ele < 0) ele = ele * -1;

        sort(begin(nums),end(nums));

        int n = nums.size();
        long long x = 0;

        long long z = 0;
        for(auto ele : nums) z += (ele * ele);

        int count = n - n/2;

        int j = n - 1;
        while(count){
            x += (nums[j] * nums[j]);
            count--;
            j--;
        }

        long long y  = z - x;

        return (x - y);


    }
};