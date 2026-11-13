class Solution {
public:
    bool f(int i, int j, string& s, string& t){

        while(true){
            if(s[i] == t[j]) {
                i++;
                j++;
            }else{ // s[i] != t[j]
                while(i < s.length() && j < t.length() && s[i] != t[j]){
                    i++;
                }
            }

            if(i >= s.length() || j >= t.length()) break;
        }

        return (j == t.length());
    }


    string findLongestWord(string s, vector<string>& arr) {
        string ans = "" ;
        //algorithm


        for(auto &str: arr){
          
            if(f(0, 0, s, str)){
                if(ans == ""){
                    ans = str;
                }else{// means ans is not empty
                    if(str.length() > ans.length()){
                        ans = str;
                    }else if(str.length() == ans.length()){
                        ans = min(str, ans);
                    }
                }
            }
        }

        return ans;
    }
};