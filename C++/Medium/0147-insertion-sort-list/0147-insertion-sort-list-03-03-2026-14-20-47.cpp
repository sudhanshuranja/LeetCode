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
    ListNode* insertionSortList(ListNode* head) {

        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);  // Sorted list dummy
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next;

            // Find position in sorted list
            ListNode* prev = dummy;

            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy->next;
    }
};