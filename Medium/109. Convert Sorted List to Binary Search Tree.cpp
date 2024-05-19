/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* makeBST(vector<int>&values,int start,int end){
        TreeNode* cur_rootNode = new TreeNode;
        int mid = (start+end)/2;
        if(mid-1 >= start)
            cur_rootNode->left = makeBST(values,start,mid-1);
        if((mid+1)<= end)
            cur_rootNode->right = makeBST(values,mid+1,end);
        cur_rootNode->val = values[mid];
        return cur_rootNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        vector<int>values;
        while(head){
            values.push_back(head->val);
            head = head->next;
        }
        int n = values.size();
        TreeNode*root= makeBST(values,0,n-1);
        return root;
    }
};
