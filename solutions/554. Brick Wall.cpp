class Solution {
public:
    int leastBricks(vector<vector<int>>& a) {
        
        for(vector<int> &v:a) {
            for(int i=1; i<v.size()-1; i++) {
                v[i]+=v[i-1];
            }
        }
        
        //int maxi=0;
        unordered_map<int,int> uom;
        for(vector<int> &v:a) { 
            for(int i=0; i<v.size()-1; i++) {
                uom[v[i]]++;
                //maxi=max(maxi, uom[v[i]]);
            }
        }
        
        int maxi=0;
        for(auto &kvp: uom){
            maxi=max(maxi, kvp.second);
        }
        
        return a.size()-maxi;
    }
};
