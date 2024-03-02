class Solution {
public:
    void inorderTraversal(TreeNode* cur, TreeNode* &prev, TreeNode* &first, TreeNode* &last){
        if(cur==nullptr) return;
        inorderTraversal(cur->left,prev,first,last);

        if(prev!=nullptr){
            if(prev->val > cur->val) {
                if(first==nullptr) first = prev;
                last = cur;
            }
            
        }

        prev = cur;
        inorderTraversal(cur->right,prev,first,last);

    }
    void recoverTree(TreeNode* root) {
        TreeNode *prev=nullptr, *first=nullptr, *last=nullptr;
        inorderTraversal(root,prev,first,last);
        swap(first->val,last->val);
    }
};
