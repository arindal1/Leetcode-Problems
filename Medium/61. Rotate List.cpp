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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL) {
            temp = temp->next;
            length++;
        }
        k = k % length;
        if(k == 0)
            return head;
        int count = 0;
        ListNode* end = head;
        ListNode* ans = head->next;
        ListNode* last = head;
        while(count < k) {
            end = end->next;
            count++;
        }
        while(end->next != NULL) {
            end = end->next;
            ans = ans->next;
            last = last->next;
        }
        end->next = head;
        last->next = NULL;
        return ans;
    }
};
