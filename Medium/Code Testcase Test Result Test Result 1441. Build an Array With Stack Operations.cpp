class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int temp = 0;
        int i = 1;
        while (temp < target.size()) {
            if (target[temp] == i) {
                ans.push_back("Push");
                temp++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};

