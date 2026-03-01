/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // Step 1: Create copy of each node
        while(temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        // Step 2: Connect next and random
        while(temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};