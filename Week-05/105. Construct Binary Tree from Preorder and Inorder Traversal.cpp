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
    int index=0;
    int findNodeLocInInOrder(vector<int> &in, int l, int h, int key) {
        for(int i=l; i<=h; i++) {
            if(in[i]==key) {
                return i;
            }
        }
        return -1;
    }
    
    TreeNode* CreateBinaryTree(vector<int>& pre, vector<int>& in, int l, int h) {
        if(l>h) return nullptr;
        TreeNode* node=new TreeNode(pre[index++]);
        if(l==h)    return node;        
        
        int loc = findNodeLocInInOrder(in, l, h, node->val);
        
        node->left=CreateBinaryTree(pre, in, l, loc-1);
        node->right=CreateBinaryTree(pre, in, loc+1, h);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return CreateBinaryTree(preorder, inorder, 0, preorder.size()-1);
    }
};
