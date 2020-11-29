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
    
    int arrowLength(TreeNode *node) {
        if(node==nullptr)   return 0;
        
        int left = arrowLength(node->left);
        int right = arrowLength(node->right);
        int arrowLeft = 0  , arrowRight = 0;    
        
        if(node->left != nullptr && node->left->val == node->val) {
            arrowLeft += left + 1;
        }
        
        if(node->right != nullptr && node->right->val == node->val) {
            arrowRight += right + 1;
        }
        
        ans = max(ans, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        ans=0;
        arrowLength(root);
        return ans;
    }   
};
