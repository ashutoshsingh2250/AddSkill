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
    int k, ans=-1;   
    void PrintInOrder(TreeNode *root){
        if(root == NULL)    return ;
        PrintInOrder(root->left);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        PrintInOrder(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        int count=0;
        PrintInOrder(root);
        return ans;
    }
};
