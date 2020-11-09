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
    
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    
    void PrintLevelOrder(TreeNode* node) {
        
        if(!node)   return;
        q.push(node);
        
        while(!q.empty()) {
            
            int size=q.size();
            //cout << size << " ";
            vector<int> v;
            
            while(size--) { 
                TreeNode* t=q.front();
                if(t) v.push_back(t->val);
                q.pop();
                if(t->left)    q.push(t->left);
                if(t->right)    q.push(t->right);
            }
            ans.push_back(v);
        }
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //vector<vector<int>> ans;
        PrintLevelOrder(root);
        return ans;
        
    }
};
