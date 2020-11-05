class Solution {
    stack<int> s;
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        int c=nums.size();  
        for(int i=2*c-1; i>=0; i--) {
            while(!s.empty() && nums[i%c]>=nums[s.top()])
                s.pop();
            res[i%c]=s.empty()?-1:nums[s.top()];
            s.push(i%c);
        }
        return res;
    }
};
