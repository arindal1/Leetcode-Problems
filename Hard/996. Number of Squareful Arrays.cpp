class Solution {
public:
    bool isSquareful(int sum){
        int sq = sqrt(sum);
        return sq*sq==sum;
    }
    void uniquePermuteHelper(int i,int n,int &ans,vector<int> nums){
        if(i==n){
            ans++;
            return;
        }
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[i]) continue;
            swap(nums[i],nums[j]);
            if(i==0|| isSquareful(nums[i]+nums[i-1])){
                uniquePermuteHelper(i+1,n,ans,nums);
            }
            
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        uniquePermuteHelper(0,n,ans,nums);

        return ans;
    }
};
