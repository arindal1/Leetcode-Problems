class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if (sx == fx && sy == fy) {
            if (t == 1)
                return false;
            
        }
        int m = max (abs (sx - fx), abs (sy - fy));
        if (m <= t)
            return true;
        return false;
    }
};
