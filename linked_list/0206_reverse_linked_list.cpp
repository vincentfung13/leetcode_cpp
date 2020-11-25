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
    ListNode* reverseList(ListNode* head) {
        /**
        // Iterative solution
        if (!head) {
            return nullptr;
        }
        
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (ptr) {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        return prev;
        **/
        
        // Recursive solution
        // Safety check
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* reversed = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversed;
    }
};
