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
    ListNode* partition(ListNode* head, int x) {

        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                less->next = new ListNode(temp->val);
                less = less->next;
            } else {
                greater->next = new ListNode(temp->val);
                greater = greater->next;
            }
            temp = temp->next;
        }

        
        less->next = greaterHead->next;

        return lessHead->next;
    }
};