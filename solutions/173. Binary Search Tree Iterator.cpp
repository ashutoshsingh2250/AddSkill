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
class BSTIterator {
    set<int> v;
    set<int>::iterator i;
    
    void PrintInOrder(TreeNode* node) {
        if(!node)   return;
        PrintInOrder(node->left);
        v.insert(node->val);
        PrintInOrder(node->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        PrintInOrder(root);
        i=v.begin();
    }
    
    /** @return the next smallest number */
    int next() {
        return *i++;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return i!=v.end();
    }
};
​
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
