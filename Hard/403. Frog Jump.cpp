class Solution {
public:
    bool inline isV(int i, int n) {
        return (i >= 0 && i <= n);
    }
    bool f(map<int, bool>& m, map<pair<int, int>, bool>& dp, int i, int n, int cj) {
        if (i > n)
            return false;
        if (i == n)
            return true;
        if (dp.find({i, cj}) != dp.end())
            return dp[{i, cj}];
        
        bool canCross = false;
        for (int j = -1; j <= 1; j++) {
            if (isV(i + cj + j, n) && cj + j != 0) {
                if (m[i + cj + j]) {
                    canCross |= f(m, dp, i + cj + j, n, cj + j);
                }
            }
            if (canCross)
                break;
        }
        return dp[{i, cj}] = canCross;
    } 
    bool canCross(vector<int>& s) {
        if (s[1] != 1)
            return false;
        
        map<int, bool> m;
        map<pair<int, int>, bool> dp;
        for (int i = 1; i < s.size(); i++) {
            m[s[i]] = true;
        }
        return f(m, dp, s[1], s.back(), 1);
    }
};
