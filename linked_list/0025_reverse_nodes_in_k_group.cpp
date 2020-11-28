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
        ListNode* slow = head;
        ListNode* slowPrev = nullptr;
        ListNode* fast = head;
        ListNode* fastNext = nullptr;
        ListNode* newHead = nullptr;
        
        while (fast) {
            for (int i = 0; i < k - 1; i++) {
                fast = fast->next;
                if (!fast) {
                    return newHead ? newHead:head;
                }
            }
            fastNext = fast->next;
            
            // Disconnect and reverse group
            fast->next = nullptr;
            if (slowPrev) {
                slowPrev->next = nullptr;
            }
            ListNode* reversedHead = reverseList(slow);
            cout << reversedHead->val << endl;
            
            // The new head of the list is the first 
            // reversed head
            if (!newHead) {
                newHead = reversedHead;
            }
            
            // Connect it back
            if (slowPrev) {
                slowPrev->next = reversedHead;
            }
            ListNode* tmp = reversedHead;

            slow->next = fastNext;
            slowPrev = slow;
                
            // Move both pointers to next group
            slow = fastNext;
            fast = fastNext;
        }
        return newHead;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        ListNode* nextPrt = nullptr;
        while (ptr) {
            nextPrt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nextPrt;
        }
        return prev;
    }
};