class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfFlooredPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), i = 0;
        long sum = 0;
        while(i < n){
            auto x = upper_bound(nums.begin(),nums.end(),nums[i]);
            int j = x - nums.begin(), k = i, c = 2;
            long tmp_sum = 0, duplicates = x - (nums.begin() + i);
            i = j;
            while(j < n){
                int y = nums[k] * c;
                int ind = upper_bound(nums.begin(),nums.end(),y - 1) - nums.begin();
                tmp_sum = (tmp_sum + (ind - j) * (c - 1)) % mod;
                j = ind;
                c++;
            }
            tmp_sum = tmp_sum * duplicates + (duplicates * duplicates);
            sum = (sum + tmp_sum) % mod;
        }
        return sum;
    }
};
