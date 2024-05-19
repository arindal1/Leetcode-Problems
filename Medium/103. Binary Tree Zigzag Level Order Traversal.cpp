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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if(root==NULL) return r;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> c;
        int level=0;
        while(!q.empty()){
            TreeNode * temp=q.front();
            q.pop();
            c.push_back(temp->val);
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            if(q.front()==NULL){
                if(level++%2!=0) reverse(c.begin(),c.end());
                r.push_back(c);
                c.clear();
                q.pop();
                if(!q.empty()) q.push(NULL);

            }

        }
        return r;
    }
};
