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
    //  - Facts
    //      - Nodes in each list less than 50
    //      - Both nodes are already sorted
    //  - Strategy
    //      - Pop each head node from each list in descending order
    //      - When one is drained just copy all the rest over
    //      - Runtime m + n == O(m + n)
    //      - Space constant
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* out = nullptr, *head = nullptr;
        while (list1 != nullptr && list2 != nullptr) {
            ListNode*& next = (list1->val < list2->val) ? list1 : list2;
            if (out == nullptr) {
                out = head = next;
                next = next->next;
                head->next = nullptr;
            } else {
                head->next = next;
                head = head->next;
                next = next->next;
                head->next = nullptr;
            }
        }
        
        ListNode* remainder = (list1 != nullptr) ? list1 : list2;
        if (out == nullptr) {
            return remainder;
        } else {
            head->next = remainder;
        }
        
        return out;
    }
};
