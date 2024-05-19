class Solution {
public:
      bool isPalindrome(string S)
    {
    for (int i = 0; i < S.length() / 2; i++) {
 
        if (S[i] != S[S.length() - i - 1]) {
            return false;
        }
    }
    return true;
    }
    void helper(string s, vector<string> &currentPartition, vector<vector<string>> &ans){
        if(s.length() == 0){
            ans.push_back(currentPartition);
            return;
        }
        for(int i=1; i <= s.length(); i++){
            string prefix = s.substr(0, i);
            string remaining = s.substr(i); 

            if(isPalindrome(prefix)){
                currentPartition.push_back(prefix);
                helper(remaining, currentPartition, ans);
                currentPartition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> currentPartition;
        vector<vector<string>> ans;
        helper(s, currentPartition, ans);
        
        return ans;
    }
};
