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
    
    TreeNode* createBST(int l, int h, vector<int> &nums){
        if(l<=h) {
            int mid=(l+h)/2;
            TreeNode* t;
            //cout << nums[mid] << " ";
            if(l==h) {
                t=new TreeNode(nums[mid]);
            } else {
                t=new TreeNode(nums[mid]);
                t->left=createBST(l, mid-1, nums);
                t->right=createBST(mid+1, h, nums);
            }
        
            return t;
        }
        return nullptr;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *t=nullptr;
        t=createBST(0, nums.size()-1, nums);
        return t;
    }
};
