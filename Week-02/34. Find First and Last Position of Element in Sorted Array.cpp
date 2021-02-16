enum SearchType {FIRST, LAST};
​
class Solution {
    
    int binarySearch(vector<int> &v, int l, int h, int k, SearchType &S) {
        if(l>h) return -1;
​
        int m=l+(h-l)/2;
​
        if(v[m]==k) {
            if(S==FIRST) {
                if(m>l && v[m]==v[m-1]) {
                    return binarySearch(v, l, m-1, k, S);
                }
            }
            
            if(S==LAST) {
                if(m<h && v[m]==v[m+1]) {
                    return binarySearch(v, m+1, h, k, S);
                }
            }
            return m;
        } 
        else if(v[m]<k) return  binarySearch(v, m+1, h, k, S);
        else return binarySearch(v, l, m-1, k, S);
​
        return -1;
    }
    
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v{-1,-1};
        SearchType S = FIRST;
        int first = binarySearch(nums, 0, nums.size()-1, target, S);
            
        S = LAST;
        int last = binarySearch(nums, 0, nums.size()-1, target, S);
        
        //cout << first << " " << last;
        
        v[0]=first, v[1]=last;
        return v;
    }
};
