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
using ll = unsigned long long;
​
class Solution {    
    queue<pair<TreeNode*, ll>> level;
    ll max_index_difference=1;
    
    void PrintLevelOrder(TreeNode* node) {
        if(!node)   return;
        level.push({node, 1});
        
        while(!level.empty()) {            
            ll size=level.size();
            ll start_index=level.front().second, curr_index;
            
            while(size--) {
                TreeNode* t=level.front().first;
                curr_index=level.front().second;
                level.pop();
​
                if(t->left)    level.push({t->left, 2*curr_index});
                if(t->right)    level.push({t->right, 2*curr_index+1});
            }
            
            max_index_difference = std::max(max_index_difference, (curr_index-start_index)+1);
            
        }
        
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        PrintLevelOrder(root);
        return max_index_difference;
    }
};
