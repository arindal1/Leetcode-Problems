class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        for (int i = 3; i < n; ++i) {
            int x0 = distance[i];
            int x1 = distance[i-1];
            int x2 = distance[i-2];
            int x3 = distance[i-3];
            if (x0 >= x2 && x1 <= x3) {
                return true;
            }
            if (i >= 4) {
                int d1 = x2 - distance[i-4];
                int d2 = x3 - x1;
                int x5 = 0;
                if (i >= 5) {
                    x5 = distance[i-5];
                }
                if (d1 >= 0 && d1 <= x0 && d2 >= 0 && d2 <= x5) {
                    return true;
                }
            }
        }
        return false;
    }
};
