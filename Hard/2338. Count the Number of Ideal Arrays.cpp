class Solution {
public:
#define ll long long
    vector<ll> fac[10005];
    void init(int maxValue){
        for(int i=1; i<=maxValue; i++){
            int j=2*i;
            while(j <= maxValue){
                fac[j].push_back(i);
                j += i;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        init(maxValue);
        int mod = 1e9+7;
        ll res = 0;
        vector<vector<ll>> dp(15, vector<ll>(maxValue+1));
        for(int j=1; j<=maxValue; j++){
            dp[1][j] = 1;
            dp[1][0] += 1;
        } 

        for(int i=2; i<=n && i<15; i++){
            for(int j=1; j<=maxValue; j++){
                for(int k : fac[j]){
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
                    dp[i][0] += dp[i][j];
                    dp[i][0] %= mod;
            }
        }
        vector<vector<ll>> nCk(10005, vector<ll>(15, 0));
        nCk[0][0] = 1;
        for(int i=1; i<=n; i++){
            nCk[i][0] = 1;
            for(int j=1; j<=i && j<15; j++){
                nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1])%mod;
            }
        }
        for(int i=1; i<=n && i<15; i++){
            res = (res + dp[i][0] * nCk[n-1][i-1])%mod;
        }

        return res;

    }
};
