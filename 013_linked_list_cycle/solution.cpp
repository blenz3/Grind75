/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Strategy
    //  - Facts
    //      - There may or may not be a cycle
    //      - Receive pointer to the head and just return bool
    //  - Algo
    //      - Approach 1: Hashtable
    //          - Walk to the end of the list and capture each node address in the hashtable
    //          - If any has been discovered before then we have a cycle
    //          - If we reach the end then no cycle
    //          - Runtime linear with respect to nodes
    //          - Space linear with respect to nodes
    //      - Approach 2: Floyd's algorithm
    //          - Fast pointer and slow pointer. 
    //          - Each time slow moves one then fast moves two
    //          - If they ever collide then there is a cycle
    //          - If fast reaches the edge then there is no cycle
    bool hasCycle(ListNode *head) {
        // Approach 2
        ListNode* fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        
        return false;
    }
};
