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
    vector<TreeNode*> f(int s, int e) {
        if (s > e) {
            vector<TreeNode*> nul = {NULL};
            return nul;
        }
        vector<TreeNode*> ans;
        for (int i = s; i <= e; i++) {
            vector<TreeNode*> l = f(s, i - 1);
            vector<TreeNode*> r = f(i + 1, e);

            if (l.size() == 0) l.push_back(nullptr);
            if (r.size() == 0) r.push_back(nullptr);

            for (auto lt : l) {
                for (auto rt : r) {
                    ans.push_back(new TreeNode(i, lt, rt));
                }
            }
        }
        return ans;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return f(1, n);
    }
};
