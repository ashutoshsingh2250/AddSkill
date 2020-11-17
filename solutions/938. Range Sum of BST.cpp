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
    int sum=0;
    
    void PrintInOrder(TreeNode* &root, int& low, int& high) {
        if(!root)   return ;
        
        if(low < root->val) PrintInOrder(root->left, low, high);
        if(root->val >= low && root->val <=high)  sum+=root->val;
        if(high > root->val) PrintInOrder(root->right, low, high);
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        PrintInOrder(root, low, high);
        return sum;
    }
};
