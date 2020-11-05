class Solution {
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1,-1};
        
        int i;
        for(i=0; i<nums.size(); i++) {
            if(nums[i] == target) {
                v[0]=i;
                break;
            }
        }
​
        if(v[0] == -1) {
            return v;
        }
        
        //cout << i;
        for(i=nums.size()-1; i>=0; i--) {
            if(nums[i] == target) {
                v[1]=i;
                break;
            }
        }
        
        //cout << i;
        return v;
    }
};
