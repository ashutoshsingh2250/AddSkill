class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& r) {
        if(r.empty()) return r;        
        std::vector<std::vector<int>> res;
​
        for(int i=0; i<r.size()-1; i++) {
            
            if(r[i][1] >= r[i+1][0]) {
                r[i+1][0] = r[i][0];
                r[i+1][1] = std::max(r[i][1], r[i+1][1]);
                r[i][0] = -1;
            }
        }
        for(auto it=r.begin(); it!=r.end(); it++) {
            auto v=*it;
            if(v.at(0) != -1) res.push_back(*it);
        }
        return res;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            intervals.push_back(newInterval);   
            return intervals;        
        }
        
        int can_be_inserted = 0;
        for(int i=0; i<intervals.size(); i++) {
            if(newInterval[0] <= intervals[i][1] && newInterval[1] >= intervals[i][0]) {
                can_be_inserted = 1;
                intervals[i][0] = min(newInterval[0], intervals[i][0]);
                intervals[i][1] = max(newInterval[1], intervals[i][1]);
                break;
            } 
        }
        
        if(can_be_inserted)
            return merge(intervals);
