/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,string s,vector<string>& ans){
        if(root==nullptr)
            return;
        s=s+to_string(root->val);
        if(root->left==nullptr && root->right==nullptr)
            ans.push_back(s);
        else if(root->left==nullptr)
            solve(root->right,s,ans);
        else if(root->right==nullptr)
            solve(root->left,s,ans);
        else{
            solve(root->left,s,ans);
            solve(root->right,s,ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        string s="";
        vector<string> ans;
        solve(root,s,ans);
        int sol=0;
        for(int i=0;i<ans.size();i++)
        {
            sol=sol+stoi(ans[i]);
        }
        return sol;
    }
};
