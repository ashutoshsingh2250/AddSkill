/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> s;
    
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    TreeNode* next() {
        TreeNode* node = s.top(); s.pop();
        TreeNode* tmp = node->right;
        while (tmp) {
            s.push(tmp);
            tmp = tmp->left;
        }
        return node;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    
    TreeNode* peekNext() {    
        return s.empty() ? nullptr : s.top();
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        BSTIterator it1(root1);
        BSTIterator it2(root2);
        
        TreeNode* node1; TreeNode* node2;
        while(it1.hasNext() || it2.hasNext()) {
            node1=it1.peekNext();
            node2=it2.peekNext();
            
            if(node1 && node2) {
                if(node1->val < node2->val) {
                    ans.push_back(node1->val);
                    it1.next();
                } else {
                    ans.push_back(node2->val);
                    it2.next();
                }
            } else {
                if (node1) {
                    ans.push_back(node1->val);
                    it1.next();
                } else {
                    ans.push_back(node2->val);
                    it2.next();
                }
            }     
        }
        
        /*if(it1.hasNext()) {
            while(it1.hasNext()) {
                ans.push_back(node1->val);
                it1.next();
            }
        } else if(it2.hasNext()) {
            while(it2.hasNext()) {
                ans.push_back(node2->val);
                it2.next();
            }
        }*/
        
        return ans;
    }
};
