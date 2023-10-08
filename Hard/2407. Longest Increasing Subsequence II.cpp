class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        map<int, int> sequences;
        
        for (auto num: nums) {
            auto it_num = sequences.emplace(num, 1).first;
            for (auto it_seq = sequences.lower_bound(num - k); it_seq != it_num; ) {
                it_num->second = max(it_num->second, it_seq->second + 1);
                if ((it_seq->first + 1 == num) || 
                    ((it_num->first - it_seq->first) <= (it_num->second - it_seq->second))) {
                    it_seq = sequences.erase(it_seq);
                }
                else {
                    ++it_seq;
                }
            }
        }
        
        return max_element(sequences.begin(), sequences.end(), [](auto s1, auto s2) { return s1.second < s2.second; })->second;
    }
};
