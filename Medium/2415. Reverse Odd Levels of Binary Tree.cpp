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
    TreeNode* reverseOddLevels(TreeNode* rootNode) {
        preOrder(rootNode->left, rootNode->right, 1);
        return rootNode;
    }

private:
    void preOrder(TreeNode* rootLeft, TreeNode* rootRight, int levelNumber) {
        if(rootLeft && rootRight) {
            if(levelNumber % 2) {
                swap(rootLeft->val, rootRight->val);
            }
            preOrder(rootLeft->left, rootRight->right, levelNumber+1);
            preOrder(rootLeft->right, rootRight->left, levelNumber+1);
        }
    }
};
