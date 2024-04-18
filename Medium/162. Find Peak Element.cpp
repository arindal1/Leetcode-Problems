class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        size_t left = 0, right = nums.size() - 1;
        while (left < right) {
            size_t mid = (right + left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
