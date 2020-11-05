/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* t) {
        ListNode *p=NULL;
        ListNode *res=t;
        while (t!=NULL && t->next!=NULL) {
            if(t->val == t->next->val) {
                p=t->next->next;
                //free(t->next);
                t->next=p;
            }
            else {
                t=t->next;
            }
        }
        
        
        return res;
    }
};
