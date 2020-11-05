class Solution {
    /*vector<string>& generateKeys(const string &k) {
        cout << k << endl;
        vector<string> vsplit, keys; int i=0;
        stringstream ss(k); string token;
        while(getline(ss, token, '.')) {
            vsplit.push_back(token);
            cout << vsplit[i] << " ";
            i++;
        }
        
        keys[0]="Dummy";
        string key;
        for(string s: vsplit) {
            key+= "."+string(s);
            keys.push_back(key);
        }
        
        return keys;
    }*/
    
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> uom;
        
        for(string &v: cpdomains) {
            string token;
            string val_key[2];
            stringstream ss(v);
            int i=0;
            while(getline(ss, token, ' ')) {
                val_key[i]=token;
                i++;
            }
            //cout << val_key[0] << " " << val_key[1] << endl;
            //vector<string> &keys=generateKeys(val_key[1]);
            vector<string> keys, vsplit;
            //i=0;
            stringstream sss(val_key[1]); 
