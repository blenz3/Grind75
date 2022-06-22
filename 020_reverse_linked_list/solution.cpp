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
        ListNode* current = head, *previous = nullptr;
        while (current != nullptr) {
            auto tmp = current->next;
            current->next = previous;
            previous = current;
            current = tmp;
        }
        
        return previous;
        
    }
    
#if 0
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> nodes;
        while (head != nullptr) {
            nodes.push(head);
            head = head->next;
        }
        
        ListNode* out = nullptr, *runner = nullptr;
        while(!nodes.empty()) {
            auto top = nodes.top();
            if (out == nullptr) {
                out = runner = top;
            } else {
                runner->next = top;
                runner = runner->next;
                runner->next = nullptr;
            }
            nodes.pop();
        }
        return out;
    }
#endif
};
