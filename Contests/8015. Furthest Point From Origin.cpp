/*
You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.

In the ith move, you can choose one of the following directions:

move to the left if moves[i] = 'L' or moves[i] = '_'
move to the right if moves[i] = 'R' or moves[i] = '_'
Return the distance from the origin of the furthest point you can get to after n moves.
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cur=0, n=moves.length(), j=1;
        vector<vector<int>> dp(n+1, vector<int> (2,0));
        
        for (char i: moves) {
            if (i=='L') {
                dp[j][0] = dp[j-1][0]-1;
                dp[j][1] = dp[j-1][1]-1;
            }
            else if (i=='R') {
                dp[j][0] = dp[j-1][0]+1;
                dp[j][1] = dp[j-1][1]+1;
            }
            else {
                dp[j][0] = dp[j-1][0]-1;
                dp[j][1] = dp[j-1][1]+1;
            }
            j++;
        }
        return max (abs(dp[n][0]), dp[n][1]);
    }
};
