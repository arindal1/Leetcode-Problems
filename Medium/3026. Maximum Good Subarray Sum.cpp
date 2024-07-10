class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        vector<long long int>pre(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        
        map<long long int,long long int>mp;

        long long int maxi=-3e18;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                if(mp[(nums[i])]>0){
                    if(pre[i-1]-pre[mp[(nums[i])]-1]>=0){
                    
                }else{
                mp[nums[i]]=i;
            }
                }
                else{
                    if(pre[i-1]>=0){
                    
                }else{
                mp[nums[i]]=i;
            }
                    
                }
                
            }else{
                    mp[nums[i]]=i;
                }
            if(mp.count((nums[i]-k))){
                if(mp[(nums[i]-k)]>0){
                     maxi=max(maxi,pre[i]-pre[mp[(nums[i]-k)]-1]);
                }else{
                     maxi=max(maxi,pre[i]);
                }
               
            }
            
            if(mp.count((nums[i]+k))){
                if(mp[(nums[i]+k)]>0){
                     maxi=max(maxi,pre[i]-pre[mp[(nums[i]+k)]-1]);
                }else{
                     maxi=max(maxi,pre[i]);
                }
               
            }
        }
        if(maxi==-3e18){
            return 0;
        }
        return maxi;
    }
};
