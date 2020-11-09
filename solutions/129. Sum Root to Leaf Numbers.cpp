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
public:
    vector<string> ans;
    string level="";
    
    void PrintPreOrder(TreeNode* node) {
        if(!node)   return;
        level+=to_string(node->val);
        if(!node->left && !node->right) {
            ans.push_back(level);
        }
        
        PrintPreOrder(node->left);
        PrintPreOrder(node->right);
        
        level.pop_back();
        
    }
    
    int sumNumbers(TreeNode* root) {
        int sum=0;
        PrintPreOrder(root);
        for(string s:ans) {
            sum+=stoi(s);
        }
        
        return sum;
    }
};
