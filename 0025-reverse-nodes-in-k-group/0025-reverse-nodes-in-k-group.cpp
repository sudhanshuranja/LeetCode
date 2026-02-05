/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node acts as a permanent anchor before the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prevGroupTail = dummy;
        
        while (true) {
            // Check if there are k nodes available to reverse
            ListNode* kth = prevGroupTail;
            for (int i = 0; i < k; ++i) {
                kth = kth->next;
                if (!kth) return dummy->next; // Fewer than k nodes remain
            }
            
            // Pointers for reversal
            ListNode* groupStart = prevGroupTail->next;
            ListNode* nextGroupHead = kth->next;
            
            // Standard iterative reversal of the k-node segment
            ListNode* prev = nextGroupHead;
            ListNode* curr = groupStart;
            for (int i = 0; i < k; ++i) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            
            // Connect the previous group to the new head of the reversed group
            prevGroupTail->next = kth;
            prevGroupTail = groupStart; // Original start is now the tail
        }
    }
};
