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
    // Strategy
    //  - Approach 1: Count nodes and move count / 2 values.
    ListNode* middleNode(ListNode* head) {
        size_t count = length(head);
        size_t nodesToWalk = (count / 2);
        for (size_t i = 0; i < nodesToWalk; ++i) {
            head = head->next;
        }
        
        return head;
    }
    
    
private:
    size_t length(ListNode* node) {
        size_t count(0);
        while (node != nullptr) {
            node = node->next;
            count++;
        }
        
        return count;
    }
};
