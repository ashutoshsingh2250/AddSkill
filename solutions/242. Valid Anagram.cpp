class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26,0);        
        for(int i=0; i<s.size(); i++){
            ++v[s[i]-97];
        }
        for(int i=0; i<t.size(); i++){
            --v[t[i]-97];
        }
        
        for(int i=0; i<26; i++) {
            if(v[i]!=0) return false;
        }
        
        /*for(auto it=v.begin(); it!=v.end(); it++) {
            if(*it!=0) return false;
        }*/
        return true;
    }
};
