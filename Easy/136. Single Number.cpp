class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        int ans;
         for (int num : nums)
        {
        frequencyMap[num]++;
        }
        for (const auto& pair : frequencyMap)
        {
        if (pair.second == 1) 
             ans = pair.first;
    }
    return ans;
    }
};
