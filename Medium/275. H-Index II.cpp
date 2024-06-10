class Solution {
public:
    static bool chk(int mid, vector<int> &citations){
        int cnt=citations.size();
        for(auto&x:citations){
            if(x<mid)cnt--;
        }
        return (cnt>=mid);
    }
    int hIndex(vector<int>& citations) {
        int lo=1, hi=citations.size();
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(chk(mid,citations)){
                ans=max(ans,mid);
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        return ans;
    }
};
