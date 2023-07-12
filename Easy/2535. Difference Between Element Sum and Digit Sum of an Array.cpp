class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elsum=0, disum=0;
        for (auto i:nums)
        {
            elsum+=i;
            while(i)
            {
                disum+=i%10;
                i/=10;
            }
        }
        return abs(elsum-disum);
    }
};
