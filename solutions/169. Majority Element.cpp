class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
​
        for(int key : nums) {
            um[key]++;
        }
​
        pair<int, int> p = make_pair(0, 0);
        for(auto it=um.begin(); it!=um.end(); it++) {
            if(it->second > p.second) {
                p=make_pair(it->first,it->second);
            }
        }
        return p.first;
    }
};
