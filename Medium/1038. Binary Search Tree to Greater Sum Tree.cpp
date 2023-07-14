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
    void solve(TreeNode* root, int &num){
        if(root == NULL){
            return;
        }
        solve(root->right, num);
        if(root -> val >= 0)
            root -> val += num;
        root -> val = -root->val;
        num = abs(root -> val);

        if(root -> left){
            solve(root -> left, num);
            if(root -> val > 0)
                num += root -> val;
        }
    }

    void recSol(TreeNode* root){
        if(!root){
            return;
        }

        root -> val = -root -> val;
        recSol(root -> left);
        recSol(root -> right);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int num = 0;
        solve(root, num);
        recSol(root);
        return root;
    }
};
