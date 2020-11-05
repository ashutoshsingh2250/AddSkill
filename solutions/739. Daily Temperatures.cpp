class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int> s;
        vector<int> ans(a.size());
        
        for(int i=0; i<a.size(); i++) {
            while(!s.empty() && a[i]>a[s.top()]) {
                int index=s.top();
                s.pop();
                ans[index]=i-index;
            }
            s.push(i);
        }
        
        return ans;
    }
};
