class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n = nums.size();
        int threshold = n / 3;

        for(auto ele: nums) m[ele]++;

        vector<int>ans;

        for(int i = 0; i < n; i++){
            if(m.find(nums[i]) == m.end()) continue;
            if(m[nums[i]] > threshold){
                ans.push_back(nums[i]);
                m.erase(nums[i]);
            }
        }

        return ans;
    }
};