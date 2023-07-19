/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void preorder(TreeNode* cloned, TreeNode* target, TreeNode* &node)
    {
        if(cloned==NULL)return;
        if (cloned->val == target->val)
            node = cloned;
        preorder(cloned->left, target, node);
        preorder(cloned->right, target, node);
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (target == nullptr || cloned == nullptr) return nullptr;
        TreeNode* node = new TreeNode;
        preorder(cloned, target, node);
        return node;
    }
};
