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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        std::vector<ListNode*> curr(lists);
        ListNode* head{new ListNode()};
        ListNode* listCur{head};
        bool notFinished {true};
        while(notFinished)
        {
            int minIndex{0};
            for(int i{1}; i < curr.size(); ++i)
            {
                if(curr[minIndex]->val > curr[i]->val)
                {
                    minIndex = i;
                }
            }
            listCur->next = new ListNode(curr[minIndex]->val);
            listCur = listCur->next;
            if(!curr[minIndex]->next)
            {
                curr.erase(curr.begin()+minIndex);
            }
            else
            {
                curr[minIndex] = curr[minIndex]->next;
            }
            if(curr.size() == 1)
            {
                listCur->next = curr[0];
                break;
            }
            else if(curr.empty()) break;
        }
        return head->next;   
    }
};
