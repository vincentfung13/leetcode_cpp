/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Using a set to dedup
        unordered_set<ListNode*> seen;
        ListNode *ptr = head;
        while (ptr) {
            if (seen.find(ptr) != seen.end()) {
                return true;
            }
            seen.insert(ptr);
            ptr = ptr->next;
        }
        return false;
        
        /***
        // Slow fast pointers
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
        ***/
    }
};
