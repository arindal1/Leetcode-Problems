class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int s = 0, k = 0, tk = 0,n=gas.size();
        for (int i = 0; i < n; i++) {
            k += gas[i] - cost[i];
            tk += gas[i] - cost[i];
            if (k < 0)
                k = 0, s = i + 1;
        }
        return (tk < 0) ? -1 : s;
    }
};
