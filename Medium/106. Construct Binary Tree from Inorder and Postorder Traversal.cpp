class Solution {
public:
    TreeNode* helper(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, unordered_map<int, int> &inOrder) {
        if(ps > pe || is > ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int inorderRoot = inOrder[root->val];
        int left = inorderRoot - is;
        root->left = helper(inorder, is, inorderRoot - 1,
        postorder, ps, ps + left - 1, inOrder);
        root->right = helper(inorder, inorderRoot + 1, ie,
        postorder, ps + left, pe - 1, inOrder);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inOrder;
        for(int i=0; i<inorder.size(); i++) {
            inOrder[inorder[i]] = i;
        }
        TreeNode* root = helper(inorder, 0, inorder.size() - 1,
        postorder, 0, postorder.size() - 1, inOrder);
        return root;
    }
};
