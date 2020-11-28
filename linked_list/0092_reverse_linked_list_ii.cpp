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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int delta = n - m;
        ListNode* slow = head;
        ListNode* slowPrev = nullptr;
        for (int i = 0; i < m - 1; i++){
            slowPrev = slow;
            slow = slow->next;
        }
        
        ListNode* fast = slow;
        while (delta) {
            fast = fast->next;
            delta--;
        }
        ListNode* fastNext = fast->next;
        
        // Disconnect and reverse
        if (slowPrev) {
            slowPrev->next = nullptr;
        }
        fast->next = nullptr;
        ListNode* reversedHead = reverseList(slow);
        
        // Restore the connections
        if (slowPrev) {
            slowPrev->next = fast;
        }
        slow->next = fastNext;
        return m == 1? reversedHead:head;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        while (ptr) {
            ListNode* nextPtr = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nextPtr;
        }
        return prev;
    }
};