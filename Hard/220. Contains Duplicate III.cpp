class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
         if (nums.size() < 2 || indexDiff < 1 || valueDiff < 0)
        return false;

    std::set<long long> window;

    for (int i = 0; i < nums.size(); ++i) {
        if (i > indexDiff) {
            window.erase(nums[i - indexDiff - 1]);
        }

        auto it = window.lower_bound(static_cast<long long>(nums[i]) - valueDiff);
        if (it != window.end() && *it - nums[i] <= valueDiff)
            return true;

        window.insert(nums[i]);
    }

    return false;
    }
};
