class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> smap(26), pmap(26);
        int pl=p.size();
        int sl=s.size();
        
        for(int i=0; i<pl; i++) {
            pmap[p[i]-'a']++;
        }
        
        for(int i=0; i<sl; i++) {
            
            smap[s[i]-'a']++;
            if(i>=pl) {
                smap[s[i-pl]-'a']--;
                if(smap==pmap) res.push_back(i-pl+1);
            } else {
            //if(i<pl) {
                if(smap==pmap) res.push_back(0);
            }
            
        }
        
        return res;
    }
};
