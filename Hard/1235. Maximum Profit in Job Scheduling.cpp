class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int, int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = make_tuple(endTime[i], startTime[i], profit[i]);
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = get<2>(v[i]);
            if (i > 0) {
                dp[i] = max(dp[i], dp[i - 1]);
            }
            {
                int l = 0, r = i - 1, at = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (get<0>(v[mid]) <= get<1>(v[i])) {
                        l = mid + 1;
                        at = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                if (at != -1) {
                    dp[i] = max(dp[i], dp[at] + get<2>(v[i]));
                }
            }
        }
        return dp[n - 1];
    }
};
