class Solution {
    string generateKey(string &s) { //#separated keys
        vector<int> v(26, 0);
        for(char &c: s) {
            v[c-'a']++;
        }
        
        string key;
        for(int x:v) {
            //cout << x;
            key+= to_string(x)+"#";
        }
        //cout << endl;
        
        return key;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> uom;
        
        for(int i=0; i<strs.size(); i++) {
            uom[ generateKey(strs[i]) ].push_back( strs[i] );
            //cout << "Key:" << generateKey(strs[i]) << " Val:" << strs[i] << endl;
        }
        
        vector<vector<string>> ans;
        for(auto kvp: uom) {
            ans.push_back(kvp.second);
        }
        
        return ans;
    }
};
