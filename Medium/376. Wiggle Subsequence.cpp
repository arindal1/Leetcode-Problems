class Solution {
public:
    int solve(int ind,int prevind,vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        if(ind==n)return 0;
        if(dp[ind][prevind+1]!=-1)return dp[ind][prevind+1];
        int nottake=solve(ind+1,prevind,nums,dp);
        int take=INT_MIN;
        if (prevind == -1 || 
    (nums[ind] > nums[prevind] && (ind == n - 1 || nums[ind + 1] < nums[ind])) ||
    (nums[ind] < nums[prevind] && (ind == n - 1 || nums[ind + 1] > nums[ind]))) {
    take = 1 + solve(ind + 1, ind, nums,dp);
}
        return dp[ind][prevind+1]=max(take,nottake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
