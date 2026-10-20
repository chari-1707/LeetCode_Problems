class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto ele : nums) mp[ele]++;

        vector<int>v(2, 0);

        for(int i = 0; i< nums.size(); i++){
            if(mp[nums[i]] > 1){
                v[0]++;
                mp[nums[i]] -= 2;
            }
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
        }

        v[1] = mp.size();

        return v;

    }
};