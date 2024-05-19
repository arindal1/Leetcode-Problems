/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    
        unordered_set<ListNode*> s;
        ListNode * it1;
        
        it1 = head;

        while(it1){
            if(s.find(it1)==s.end()){
                s.insert(it1);
            }
            else return it1;
            it1 = it1->next;
        
        }
        return NULL;
    }    
};
