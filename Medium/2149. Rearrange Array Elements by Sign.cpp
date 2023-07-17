class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result;
        int pos = 0, neg = 0;
        while(pos != nums.size() && neg != nums.size())
        {
            while(nums[pos] <= 0)
            {
                pos++;
            }
            result.push_back(nums[pos++]);
            while(nums[neg] > 0)
            {
                neg++;
            }
            result.push_back(nums[neg++]);
        }

        return result;
    }
};
