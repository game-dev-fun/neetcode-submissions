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
        if(!head) return head;
        ListNode* trav{head};
        ListNode* prev{nullptr};
        while(trav)
        {
            ListNode* next{trav->next};
            trav->next = prev;
            prev = trav;
            trav = next;
        }
        return prev;
    }
};
