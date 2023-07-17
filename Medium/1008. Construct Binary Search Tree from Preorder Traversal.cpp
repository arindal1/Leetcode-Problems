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
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int idx=0;
        return construct(idx,INT_MAX,pre);
    }
    TreeNode* construct(int &idx, int bound, vector<int> &pre){
        if(idx==pre.size()||pre[idx]>bound) return NULL;
        TreeNode* root=new TreeNode(pre[idx]);
        idx++;
        root->left=construct(idx,root->val,pre);
        root->right=construct(idx,bound,pre);
        return root;
    }
};

