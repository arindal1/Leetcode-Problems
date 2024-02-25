class Solution {
public:
    vector<string> ans;
    void backtrack(string& s, string path, int index,  int count) {
        if (count > 4) return;
        if (count == 4 && index >= s.length()) {
            path.pop_back();
            ans.push_back(path);
            return;
        }
        for (int i = 1; i <= 3 && index + i <= s.length(); i++) {
            string num = s.substr(index, i);
            if (num[0] == '0' && i != 1) break;
            else if (stol(num) <= 255) {
                backtrack(s, path + s.substr(index, i) + ".", index + i,count + 1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, "", 0, 0);
        return ans;
    }
};
