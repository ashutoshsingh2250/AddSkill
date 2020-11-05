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
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        ListNode *l3=NULL; // resultant linked list
        ListNode *l3root=NULL;
        int carry=0;
        while (t1!=NULL && t2!=NULL) {
            int v = t1->val + t2->val + carry;
            int data = v%10;
            carry=v/10;
            
            ListNode *newNode = new ListNode(data);
            if(l3==NULL) {
                l3=newNode;
                l3root=l3;
                //cout << l3->val;
            }
            else {
                l3->next=newNode;
                l3=l3->next;
                //cout << l3->val;
            }
            t1=t1->next;
            t2=t2->next;
        }
​
        ListNode *rem;
        if(t1!=NULL) rem=t1;
        else if(t2!=NULL) rem=t2;
