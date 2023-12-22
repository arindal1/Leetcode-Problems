class Solution {
    vector<int> dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};
    int dfs(int i, int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        int mx = 0;
        for(int k=0; k<4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
                if(dp[x][y]) mx = max(mx, dp[x][y]);
                else mx = max(mx, dfs(x, y, n, m, matrix, dp));
            }
        }
        return dp[i][j] = 1 + mx;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m));

       for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++) {
               ans = max(ans, dfs(i, j, n, m, matrix, dp));
           }
       }
       return ans;
    }
};
