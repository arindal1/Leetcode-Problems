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
    void traversal (vector<int>& v, TreeNode* node){
        if(node == NULL) return; 
        v.push_back(node->val); 
        traversal(v,node->left); 
        traversal(v,node->right); 
    }

    void flatten(TreeNode* root) {
        vector<int> v; 
        traversal(v, root); 
        TreeNode* head = new TreeNode(); 
        TreeNode* cursor = head; 
        for(int i=0; i<v.size(); i++ ){
            TreeNode* temp = new TreeNode(v[i]); 
            cursor->right = temp; 
            cursor = cursor->right; 
        }

        cursor = head->right; 
        TreeNode* cursor1 = root; 

        while(cursor){
            cursor1->val = cursor->val;
            cursor1->left = NULL; 
            cursor1->right = cursor->right; 
            cursor = cursor->right; cursor1 = cursor1->right; 
        }  

        
    }
};
