class Solution {
public:
    /*
        3,2,3,3,3,2,5,7,5,5



    */
    int minSetSize(vector<int>& arr) {
        int n = arr.size();

        map<int, int> mp;
        for (auto ele : arr)
            mp[ele]++;

        // unordered_set<int>s;
        int ans = 0;

        int x = n;

        map<int, vector<int>, greater<int>> sortedMp;

        for (auto it : mp) {
            sortedMp[it.second].push_back(it.first);
        }

        // for (auto it : sortedMp) {

        //     cout << it.first << " ";
        //     x -= (it.first);
        //     ans = ans + 1;

        //     if (x <= n / 2) {
        //         break;
        //     }
        // }

        for (auto it : sortedMp) {
            for (int ele : it.second) {
                x -= it.first;
                ans++;

                if (x <= n / 2) {
                    break;
                }
            }

            if (x <= n / 2) {
                break;
            }
        }

        // for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        //     //  cout << it->first << " " << it->second << endl;

        //     cout<<it->second<<" ";

        // x -= (it->second);
        // ans = ans + 1;

        // cout<<x<<" "<<endl;

        // if(x <= n/2) {
        //     break;
        // }
        // }

        // for(auto ele : mp){
        //     x -= ele.second;
        //     mp.erase(ele.first);
        //     // s.insert(ele.first);
        //     ans = ans + 1;
        //     if(x <= (n /2)) {
        //         break;
        //     }
        // }

        return ans;
    }
};