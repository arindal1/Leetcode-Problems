class Solution {
public:
    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
        for (int start = n; start >= 1; --start) {
            for (int end = start; end <= n; ++end) {
                if (start == end) {
                    dp[start][end] = 0;
                } else {
                    int minCost = INT_MAX;
                    for (int guess = start; guess <= end; ++guess) {
                        int cost = std::max(guess + dp[start][guess - 1], guess + dp[guess + 1][end]);
                        minCost = std::min(minCost, cost);
                    }
                    dp[start][end] = minCost;
                }
            }
        }

        return dp[1][n];
    }
};
