/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    bool isBST(TreeNode* r, long long min, long long max) {
        if(r==nullptr) 
            return true;
        if(r->val <= min || r->val >= max)  
            return false;
        if(!isBST(r->left, min, r->val) || !isBST(r->right, r->val, max))  
            return false;
        return true;
        
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        return isBST(root, LLONG_MIN, LLONG_MAX);
        
    }
};
