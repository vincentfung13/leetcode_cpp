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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // Get the tail pointer for list2
        ListNode* list2Tail = list2;
        while (list2Tail->next) {
            list2Tail = list2Tail->next;
        }
        
        // Get the head and tail of the section to remove
        ListNode* removeHead = list1;
        ListNode* removeHeadPrev = nullptr;
        ListNode* removeTail = list1;
        while (a > 0 || b > 0) {
            if (a > 0) {
                removeHeadPrev = removeHead;
                removeHead = removeHead->next;
                a--;
            }
            
            if (b > 0) {
                removeTail = removeTail->next;
                b--;
            }
        }
        
        // Distconnect original head
        if (a > 1) {
            // No need to disconnect removeHead if a == 1
            removeHeadPrev->next = nullptr;
        }
        
        // Attach list2
        if (removeHeadPrev) {
            removeHeadPrev->next = list2;
        }
        list2Tail->next = removeTail->next;
        
        // Disconnect original tail
        removeTail->next = nullptr;

        return list1;
    }
};