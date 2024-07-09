int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    int get_combination(int left,vector<int>&nums,vector<int>&dp){
        if(left==0){
            return 1;
        }
        if(left<0){
            return 0;
        }
        if(dp[left]!=-1){
            return dp[left];
        }
        int ans=0;
        for(auto ele:nums){
            ans+=get_combination(left-ele,nums,dp);
        }
        return dp[left]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return get_combination(target,nums,dp);

    }
};
