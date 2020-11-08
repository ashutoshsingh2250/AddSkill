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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3=NULL;
        ListNode* t3;
        
        if(l1==NULL && l2==NULL) return l3;
        else if(l1==NULL && l2!=NULL) return l2;
        else if(l1!=NULL && l2==NULL) return l1;
        
        if(l3==NULL) {
            if(l1->val <= l2->val)
            {
                ListNode* n = new ListNode(l1->val);
                t3=l3=n;
                l1=l1->next;
            } else {
                ListNode* n = new ListNode(l2->val);
                t3=l3=n;
                l2=l2->next;
            }
        }
        while(l1!=NULL && l2!=NULL) {
            if(l1->val <= l2->val) {
                ListNode* n = new ListNode(l1->val);
                l3->next=n;
                l3=n;
                l1=l1->next;  
            } else if(l2->val < l1->val) {
                ListNode* n = new ListNode(l2->val);        
                l3->next=n;
                l3=n;
                l2=l2->next;
            } 
        }      
        if(l1==NULL) {
            l3->next=l2;
        }
        if(l2==NULL) {
            l3->next=l1;
        }
        return t3;
    }
};
​
