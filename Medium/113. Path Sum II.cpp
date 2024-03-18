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
vector<int>path;
vector<vector<int>>depot;
    void bk(TreeNode* node, int tar){
        //if (!node){return;}
        if (node->left == nullptr && node->right == nullptr){
            if (node->val == tar){
                path.push_back(node->val);
                depot.push_back(path);
                path.pop_back();
            }
        }
        if (node->left != nullptr){
            path.push_back(node->val);
            bk(node->left, tar - node->val);
            path.pop_back();
        }
        if (node->right != nullptr){
            path.push_back(node->val);
            bk(node->right, tar - node->val);
            path.pop_back();
        }
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root){return {};}
        bk(root, targetSum);
        return depot;
    }
};
