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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        ListNode*curr=head;
        int top=0,right=n-1,bottom=m-1,left=0;
        while(top<=bottom && left<=right && curr){
            for(int i=left;i<=right;i++){
                if(curr){
                    mat[top][i]=curr->val;
                    curr=curr->next;
                }else{
                    break;
                }
            }
            top++;
            for(int i=top;i<=bottom;i++){
                if(curr){
                    mat[i][right]=curr->val;
                    curr=curr->next;
                }else{
                    break;
                }
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    if(curr){
                        mat[bottom][i]=curr->val;
                        curr=curr->next;
                    }else{
                        break;
                    }
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    if(curr){
                        mat[i][left]=curr->val;
                        curr=curr->next;
                    }else{
                        break;
                    }
                }
                left++;
            }
        }
        return mat;
    }
};
