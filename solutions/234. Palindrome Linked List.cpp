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
/*class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode*temp=head;
        
        if(temp==NULL || temp->next==NULL) return true;
        
        ListNode* prev=NULL;
        ListNode* t=head;
        while(t != NULL) {
            
            ListNode* temp=t->next;
            t->next=prev;
            prev=t;
            t=temp;
            
        }
        
        while(temp && prev) {
            if(temp->val == prev->val) {
                temp=temp->next;
                prev=prev->next;
            }
            else {
                return false;
            }
        }
        
        if(temp==NULL && prev==NULL)
