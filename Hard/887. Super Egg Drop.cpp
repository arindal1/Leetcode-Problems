class Solution {
public:
    int dp[102][10004];

    int solve(int e, int f){
        if(f <= 1 || e <= 1) return f;
        if(dp[e][f] != -1) return dp[e][f];
        int mn = INT_MAX;
        int low = 0, high = f;
        while(low <= high){
            int mid = low + (high-low)/2;
            int temp1 = solve(e-1,mid-1);
            int temp2 = solve(e,f-mid);
            mn = min(mn, 1 + max(temp1,temp2));
            if(temp1 > temp2) high = mid-1;
            else low = mid+1; 
        }
        return dp[e][f] = mn;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};
