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
    bool isPalindrome(ListNode* head) {
        ListNode* runnerHead = head, *runnerTail = head;
        return palindromeTraverse(runnerHead, runnerTail);
    }
    
private:
    bool palindromeTraverse(ListNode*& head, ListNode* tail) {
        if (tail == nullptr) {
            return true;
        }
        
        if (!palindromeTraverse(head, tail->next)) {
            return false;
        }
        
        if (head->val != tail->val) {
            return false;
        } 
        
        head = head->next;
        return true;
    }
};
