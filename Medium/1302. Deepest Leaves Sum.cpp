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
    int deepestLeavesSum(TreeNode* root) {

        queue<TreeNode*>que;
         int ans=0;
        que.push(root);

        que.push(NULL);
        int sum =root->val;
        ans=sum;
        sum=0;
    while(!que.empty()){
        if(que.front()==NULL && que.size()==1){
            break;

         }
        TreeNode* temp =que.front();
          if(temp==NULL){
               ans=sum;
               sum=0;
               que.push(NULL);
               
          }
          else{
            if(temp->left!=NULL){
             que.push(temp->left);

        
             sum+=temp->left->val;

           }
           if(temp->right!=NULL){
              que.push(temp->right);
             sum+=temp->right->val;
           }

          }
          
         que.pop();
    }

     return ans;   
    }
};
