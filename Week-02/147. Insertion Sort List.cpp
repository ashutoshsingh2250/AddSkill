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
    ListNode* reverse(ListNode * list) {
        ListNode *prev=NULL;
        ListNode *temp=NULL;
        while(list!=NULL) {
            temp=list->next;
            list->next=prev;
            prev=list;
            list=temp;
        }
        return prev;
    }
    
    ListNode* insertionSortList(ListNode* head) { 
        if(head == NULL) return head;
        
        ListNode *list=head;
        ListNode *root =new ListNode(list->val);
        ListNode *r, *prev;
        list=list->next;
        
        if(list==NULL) return head;
        while(list != NULL) {
            prev=NULL;
            r=root;
            while(r->next != NULL && list->val < r->val) {
                prev=r;
                r=r->next;
            }
            
            ListNode *newNode = new ListNode(list->val);
            
            if(r->next == NULL && prev==NULL) {
                if(newNode->val < r->val) {
                    r->next = newNode;
                    root=r;
                } else {
                    newNode->next=r;
                    root=newNode;
                }
            } 
            else if(r->next==NULL && prev!=NULL) {
                if(newNode->val < r->val) {
                    r->next = newNode;
                } else {
                    prev->next=newNode;
                    newNode->next=r;
                }
            } else if(prev == NULL) {
                newNode->next = root;
                root=newNode;
            } else {
                newNode->next = r;
                prev->next = newNode;
            }
            list=list->next;
        }
        return reverse(root);
    }
};
