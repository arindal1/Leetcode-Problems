class Solution {
public:
    int minimumSum(int n, int k) {
        set<int> set1;
        vector<int> v;
        int n1=1;
        while (v.size() < n) {
            if (!set1.count(n1))
                v.push_back(n1);
            set1.insert(k-n1);
            n1++;
        }
        int ans = accumulate(v.begin(),v.end(),0);
        return ans;
    }
};
