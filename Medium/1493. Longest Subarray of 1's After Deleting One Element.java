class Solution {
    public int longestSubarray(int[] nums) {
        int i = 0, j = 0, n = nums.length;
        int c0 = 0, mx = 0;
        while (j < n) {
            if (nums[j] == 0) {
                c0++;
            }
            while (i < n && c0 == 2) {
                if (nums[i] == 0) {
                    c0--;
                }
                i++;
            }
            mx = Math.max(j - i, mx);
            j++;
        }
        return mx;
    }
}
