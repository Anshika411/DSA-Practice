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
    void deleteNode(ListNode* node) { // 1 2 3 4 ; node = 2
        node ->val = node ->next ->val; // 1 3 3 4
        node->next = node ->next->next; // 1 3 4
    }
};