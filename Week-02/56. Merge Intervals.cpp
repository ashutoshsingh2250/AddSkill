bool comparator(vector<int> v1, vector<int> v2) {
    return v1.at(0) < v2.at(0);
}
​
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& r) {
        if(r.empty()) return r;
        
        std::vector<std::vector<int>> res;
        std::sort(r.begin(), r.end(), comparator);
    
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
};
​
