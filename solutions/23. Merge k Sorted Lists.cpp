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
    
    class compare {
    public:
        bool operator()(ListNode* &a, ListNode* &b) const
        {
            return a->val > b->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(ListNode* &list: lists) {
            if(list)    pq.push(list);
        }
                
        if (pq.empty())
            return nullptr;
        
        ListNode *dummy=new ListNode();
        ListNode* last=dummy;
        
        while(!pq.empty()) {
     
            ListNode* curr=pq.top();
            pq.pop();
​
            last->next=curr;
            last=last->next;
​
            if(curr->next)  pq.push(curr->next);
        }
        
        return dummy->next;
    }
};
