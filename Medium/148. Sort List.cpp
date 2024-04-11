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
    ListNode *findMiddle(ListNode *head){
        if(head==NULL or head->next==NULL)  return head;
        ListNode *slow,*fast;
        slow = head;
        fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *leftHead,ListNode *rightHead){
        ListNode *p1,*p2,*head,*tail;
        p1 = leftHead;
        p2 = rightHead;
        head = NULL;
        while(p1 and p2){
            if(p1->val <= p2->val){
                if(head==NULL){
                    head = tail = p1;
                }
                else{
                    tail->next = p1;
                    tail = p1;
                }
                p1 = p1->next;
            }
            else{
                if(head==NULL){
                    head = tail = p2;
                }
                else{
                    tail->next = p2;
                    tail = p2;
                }
                p2 = p2->next;
            }
        }
        while(p1){
            if(head==NULL){
                    head = tail = p1;
                }
                else{
                    tail->next = p1;
                    tail = p1;
                }
                p1 = p1->next;
        }
        while(p2){
            if(head==NULL){
                    head = tail = p2;
                }
                else{
                    tail->next = p2;
                    tail = p2;
                }
                p2 = p2->next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode *middle = findMiddle(head);
        ListNode *rightHead = middle->next;
        middle->next=NULL;
        head = sortList(head);
        rightHead = sortList(rightHead);
        return merge(head,rightHead);
    }
};
