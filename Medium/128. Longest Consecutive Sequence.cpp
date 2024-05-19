class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = true;
        }
        for(int i = 0; i < n; i++) {
            if(mp.count(nums[i] - 1) > 0) {
                mp[nums[i]] = false;
            }
        }
        int ml = 0;
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] == true) {
                int j = 0, c = 0;
                while(mp.count(nums[i] + j) > 0) {
                    j++;
                    c++;
                }
                if(c > ml) {
                    ml = c;
                }
            }
        }
        return ml;
    }
};
