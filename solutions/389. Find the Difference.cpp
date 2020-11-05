class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.empty())   return t[0];
        
        vector<int> vs(26), vt(26);
        
        for(char &c:s) {
            vs[c-'a']++;
        }
        for(char &c:t) {
            vt[c-'a']++;
        }
        
        for(int i=0; i<26; i++) {
            if(vs[i]!=vt[i]) return (char)(i+'a');
        }
        
        return ' ';
    }
};
