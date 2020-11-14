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
   
    int ans;
    bool found=false;
    
    void sumPath(TreeNode* node, int &res) {
        if(!node)   return ;
        res+=node->val;
        if(!node->left && !node->right) {
            if(res==ans) {
                found=true; 
                return ;
            }
        }
        
        sumPath(node->left, res);
        sumPath(node->right, res);
        
        res-=node->val;
    }
    
    
public:
    bool hasPathSum(TreeNode* root, int sum) {
        ans=sum;
        int res=0;
        sumPath(root, res);
        
        if(found)   return true;
        
        return false;
