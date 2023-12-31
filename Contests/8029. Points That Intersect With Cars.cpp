class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> line(101, 0);

    for (const vector<int>& car : nums) {
        for (int i = car[0]; i <= car[1]; ++i) {
            line[i] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i <= 100; ++i) {
        if (line[i] == 1) {
            ++count;
        }
    }
    return count;
    }
};
