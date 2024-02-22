#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0, ans = 0;
        T.insert(0);
        for (auto x : nums) {
            sum += x;
            ans += T.order_of_key(sum - lower + 1) - T.order_of_key(sum - upper);
            T.insert(sum);
        }
        return ans;
    }
};
