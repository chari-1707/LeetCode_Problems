class Solution {
public:
    /*

    [1,2,5,2,3]



    */
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        sort(begin(nums), end(nums));

        // for(int i = 0 ;i<n;i++){
        //     if(nums[i] == target){
        //         ans.push_back(i);
        //     }
        // }


        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target) {
                ans.push_back(mid);
                if ( mid - 1  >= 0 && mid + 1 < n &&nums[mid] == nums[mid + 1] && nums[mid] == nums[mid - 1]) {
                    int x = mid ;
                    while(x + 1< n && nums[x] == nums[x + 1]){
                        ans.push_back(x + 1);
                        x = x + 1;
                    }
                    x = mid;
                    while(x - 1 >=  0 && nums[x] == nums[x - 1]){
                        ans.push_back(x - 1);
                        x = x - 1;
                    }
                }
                else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                    int x = mid;
                    while(x - 1 >= 0 && nums[x] == nums[x - 1]){
                        ans.push_back(x - 1);
                        x = x - 1;
                    }
                }else{
                    int x = mid;
                    while(x + 1 < n && nums[x] == nums[x + 1]){
                        ans.push_back(x + 1);
                        x = x + 1;
                    }
                }

                break;
            }
            else if(nums[mid] < target){
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }

        sort(begin(ans), end(ans));

        return ans;
    }
};