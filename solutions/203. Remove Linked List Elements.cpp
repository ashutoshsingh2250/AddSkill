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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t=head;
        
        if(head==NULL) return head;
        
        while(t!=NULL && t->next!=NULL) {
            ListNode *p;
            
            if(t->next->val == val) {
                t->next=t->next->next;
            }
            else {
                t=t->next;
            }
        }
        
        if(head!=NULL && head->val==val)
        return head->next;
        
        return head;
    }
};
