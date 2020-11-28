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
    vector<int> nextLargerNodes(ListNode* head) {
        // Solution with a monotonic stack
        stack<int> mStack;
        
        // Generate the results vector
        tuple<int, ListNode*> t = reverseList(head);
        int listSize = get<0>(t);
        ListNode *ptr = get<1>(t);
        vector<int> results(listSize);

        int i = 0;
        while (ptr) {
            while (!mStack.empty() && ptr->val >= mStack.top()) {
                mStack.pop();
            }
            results[i] = (mStack.empty() ? 0 : mStack.top());
            mStack.push(ptr->val);
            ptr = ptr->next;
            i++;
        }
        reverse(results.begin(), results.end());
        return results;
    }
    
private:
    tuple<int, ListNode*> reverseList(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        ListNode* nextPtr = nullptr;
        int listSize = 0;
        while (ptr) {
            nextPtr = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nextPtr;
            listSize++;
        }
        return tuple<int, ListNode*>{listSize, prev};
    }
};