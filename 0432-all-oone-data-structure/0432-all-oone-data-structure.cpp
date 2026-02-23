#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    unordered_map<string, Node*> mp;

    void insertAfter(Node* node, Node* newNode) {
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (!mp.count(key)) {
            // Insert new key with count 1
            if (head->next->count != 1) {
                insertAfter(head, new Node(1));
            }
            head->next->keys.insert(key);
            mp[key] = head->next;
        } else {
            Node* curr = mp[key];
            int newCount = curr->count + 1;

            if (curr->next->count != newCount) {
                insertAfter(curr, new Node(newCount));
            }

            curr->next->keys.insert(key);
            mp[key] = curr->next;

            curr->keys.erase(key);
            if (curr->keys.empty())
                removeNode(curr);
        }
    }

    void dec(string key) {
        Node* curr = mp[key];

        if (curr->count == 1) {
            mp.erase(key);
        } else {
            int newCount = curr->count - 1;

            if (curr->prev->count != newCount) {
                insertAfter(curr->prev, new Node(newCount));
            }

            curr->prev->keys.insert(key);
            mp[key] = curr->prev;
        }

        curr->keys.erase(key);
        if (curr->keys.empty())
            removeNode(curr);
    }

    string getMaxKey() {
        if (tail->prev == head)
            return "";
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail)
            return "";
        return *(head->next->keys.begin());
    }
};