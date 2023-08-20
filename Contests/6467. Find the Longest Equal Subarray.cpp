class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l =nums.size();
        int left = 0;
        int maxl = 0;
        for (int right = 0; right < l; right++) {
            if (freq.find(nums[right]) == freq.end())
                freq[nums[right]] = 0;
        freq[nums[right]]++;
        while ((right - left+1) - freq.begin()->second > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);
        left++;
        }
        maxl = max(maxl, right - left +1);
        }
        return maxl;
    }
};
