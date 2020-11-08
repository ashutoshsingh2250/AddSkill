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
​
class Solution {
    vector<int> v;
    
    void PrintInOrder(TreeNode* r) {
        if(!r) return;
        PrintInOrder(r->left);
        
        v.push_back(r->val);
        
        PrintInOrder(r->right);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        
        PrintInOrder(root);
        return v[k-1];
        
    }
};
