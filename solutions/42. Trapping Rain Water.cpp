class Solution {
public:
    int trap(vector<int>& v) {
        int gmax=-1, gindex=-1;
        for(int i=0; i<v.size(); i++) {
            if(v[i]>gmax) {
                gmax=v[i];
                gindex=i;
            }
        }
        if(gmax==-1) return 0;
        int lsum=0,rsum=0,max=0;
        for(int i=0; i<gindex; i++) {
            if( max<v[i] ) { 
                max=v[i];
            }
            int curr=max-v[i];
            lsum += curr;
        }
        max=0;
        for(int i=v.size()-1; i>=gindex; i--) {
            if( max<v[i] ) { 
                max=v[i];
            }
            int curr=max-v[i];
            rsum += curr;
        }
        return lsum+rsum;
    }
};
