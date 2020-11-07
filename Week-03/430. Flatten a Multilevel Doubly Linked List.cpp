/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
​
class Solution {
    
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        
        while(curr) {
            if(curr->child) {
                
                Node* end=curr->next;
                Node* mid=flatten(curr->child);
                
                curr->child=nullptr;
                curr->next=mid;
                
                mid->prev=curr;
                mid->child=nullptr;
                
                while(mid->next)    
                    mid=mid->next;
                
                if(end) {
                    mid->next=end;
                    end->prev=mid;
                }
            }
            else
                curr=curr->next;
        }
        
        return head;
    }
};
