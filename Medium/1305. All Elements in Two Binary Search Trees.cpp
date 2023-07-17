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
vector<int>v;
    void traversal(TreeNode* r){
        if(!r){return;}
        v.push_back(r->val);
        traversal(r->left);
        traversal(r->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
           traversal(root1);
           traversal(root2);
           sort(v.begin(),v.end());
           return v;
    }
};
