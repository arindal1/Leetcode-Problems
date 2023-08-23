/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode t = head;
        while (t != null) {
            if (t.next != null) {
                int g = gcd(t.val, t.next.val);
                ListNode new_node = new ListNode(g);
                ListNode n = t.next;
                t.next = new_node;
                new_node.next = n;
                t = n;
            } else {
                break;
            }
        }
        return head;
    }

    private int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
