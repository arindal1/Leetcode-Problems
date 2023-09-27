class Solution:
    def canReach(self, s: str, minJump: int, maxJump: int) -> bool:
        dp = [False for _ in s]
        dp[0] = True
        num_prev_reachable = 0

        for i in range(1, len(s)):
            if i > maxJump and dp[i - maxJump - 1]:
                num_prev_reachable -= 1
            if i >= minJump and dp[i - minJump]:
                num_prev_reachable += 1
            
            # if we can reach this 0 from prev reachable spots, it is reachable
            if s[i] == "0" and num_prev_reachable > 0:
                dp[i] = True

        return dp[-1]
