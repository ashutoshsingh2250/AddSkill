class Solution {
public:
    int BS(vector<int> &a, int l, int h, int key) {
        if(h>=l && h>=0 && l>=0) {
            int m = (l+h)/2;
            if(key == a[m]) {
                return m;
            }
            else if(key < a[m]) return BS(a, l, m-1, key);
            else if(key > a[m]) return BS(a, m+1, h, key);
        }
        return -1;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        index = BS(nums, 0, nums.size()-1, target);
        if(index == -1) {
            int i;
            for(i=0; i<nums.size(); i++) {
                if(target < nums[i]) return i;
            }
            return i;
        } 
        return index;
    }
};
