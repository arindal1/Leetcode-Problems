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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
        return nullptr;

        // find max element
        int maxi=INT_MIN;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]>maxi)
           {
               maxi=nums[i];
               index=i;
           }
        }

        vector<int> leftarr;
        for(int i=0;i<index;i++)
            leftarr.push_back(nums[i]);

        vector<int> rightarr;
        for(int i=index+1;i<nums.size();i++)
            rightarr.push_back(nums[i]);

        TreeNode* node=new TreeNode(maxi);
        
        node->left=constructMaximumBinaryTree(leftarr);
        node->right=constructMaximumBinaryTree(rightarr);

        return node;
    }
};
