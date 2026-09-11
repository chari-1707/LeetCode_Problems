class Solution {
public:
/*
We have to find the distinct even numbers 

    -> so instead of building the number from the given digits Travese through all 3 digit numbers right

    -> arr = [ 1 0 3 0 ] 
        map ={
            1,1
            0,2
            3,1        
        }





*/
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        unordered_map<int,int> m;
        for(auto ele : digits){
            m[ele]++;
        }

        for(int i = 100; i <= 999; i++){
            int curr = i;

            if(i %2 != 0) continue;

            int thirdD = curr%10;
            curr /= 10;
            int secondD = curr%10;
            curr /= 10;
            int firstD = curr;

            if(m.find(firstD) != m.end()){
                m[firstD]--;
                if(m[firstD] == 0) m.erase(firstD);
                if(m.find(secondD) != m.end()){
                    m[secondD]--;
                    if(m[secondD] == 0) m.erase(secondD);
                    if(m.find(thirdD) != m.end()){
                        cout<<i<<" ";
                        ans += 1;
                    }
                    m[secondD]++;
                }
                m[firstD]++;
            }

        }

        return ans;

    }
};