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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node helps handle head changes easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;

        while (true) {
            // Step 1: Check if k nodes exist
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; // less than k nodes left

            // Step 2: Reverse k nodes
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse linked list from groupStart to kth
            ListNode* prev = nextGroupStart;
            ListNode* curr = groupStart;

            while (curr != nextGroupStart) {
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // Step 3: Connect reversed group back
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
