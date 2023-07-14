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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* adder = temp;
        while(temp){ 
            if(temp->val == 0){ 
                adder = temp;
                int add = 0; 
                while(adder->next != 0){
                    adder = adder->next; 
                    add = add + adder->val;
                    if(adder->next->val == 0){break;}
                }
                temp->val = temp->val + add;
                if(adder->next->next == nullptr){ 
                    temp->next = nullptr;
                    return head;
                }else{ 
                    temp->next = adder->next; 
                    temp = adder; 
                    temp = temp->next; 
                }
            }
        }
        return nullptr;
    }
};
