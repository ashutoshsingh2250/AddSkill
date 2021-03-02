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
    string height="";
    int sum=0;
    
    void preOrder(TreeNode* root) {
        if(root==nullptr)   return;
        if(root)    height+= to_string(root->val);
        if(root && root->left==nullptr && root->right==nullptr) {
            cout << height << endl;
            sum+=stoi(height, nullptr, 2);
            height.pop_back();
            return ;
        } 
        
        preOrder(root->left);
        preOrder(root->right);
        height.pop_back();
        
    }
    
    
public:
    int sumRootToLeaf(TreeNode* root) {
        preOrder(root);
        
        return sum;
    }
};
