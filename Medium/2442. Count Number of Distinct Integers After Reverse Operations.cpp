class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        int x  = 0;
        for(auto &i: nums){
            s.insert(i);
            x = 0;
            while(i){
                x = (x*10+(i%10));
                i /= 10;
            }
            s.insert(x);
        }
        return s.size();
    }
};
