bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.second > b.second;
}
​
class Solution {    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> ump;
        for(int &i: nums)    ump[i]++;
        
        vector<pair<int, int>> elems(ump.begin(), ump.end());
        
        //for(auto &i: elems)  cout << i.first << " " << i.second << "\t";cout<<endl;
        
        partial_sort(elems.begin(), elems.begin()+k, elems.end(), cmp); 
        //OR ELSE USE HEAPS I.E PRIORITY QUEUES INSTEAD.
        
        for(auto &i: elems) {
            //cout << i.first << " " << i.second << "\t";
            if(k-->0)     ans.push_back(i.first);
        }
        
        // for(int i=0; i<k-1; i++) {
        //     ans[i]=elems[i].first;
        // }
                
        return ans;
    }
};
