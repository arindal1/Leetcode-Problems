class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    int minShifts = n;
    for (int i = 0; i < n; ++i) {
        int shifts = 0;
        bool sorted = true;

        for (int j = 0; j < n; ++j) {
            if (nums[j] != sortedNums[(j + i) % n]) {
                sorted = false;
                break;
            }
            shifts = (j + i) % n - j;
            if (shifts < 0)
                shifts += n;
        }

        if (sorted)
            minShifts = std::min(minShifts, shifts);
    }

    return (minShifts == n) ? -1 : minShifts;
    }
};
