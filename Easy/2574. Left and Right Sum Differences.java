/* 2574. Left and Right Sum Differences
Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.
Where:

leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return the array answer. */


class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n = nums.length;
        int[] lSum = new int[n];
        int[] rSum = new int[n];
        
        for(int i=1; i<n; i++){
            lSum[i] = lSum[i-1] + nums[i-1];
        }
        for (int i = n-2; i >= 0; i--) {
        rSum[i] = rSum[i+1] + nums[i+1];
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Math.abs(lSum[i] - rSum[i]);
        }
        return ans;
    }
}
