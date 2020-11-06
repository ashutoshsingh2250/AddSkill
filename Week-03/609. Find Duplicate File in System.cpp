class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> uom;
        
        for(string &p:paths) {
            //cout << endl << "For===>" << p << endl << "::::::start::::::" << endl;
            istringstream ss(p);
            string token;
            getline(ss, token, ' ');
            string dir(token);
            while(getline(ss, token, ' ')) {
                istringstream temp(token);   
                
                string file_name;
                getline(temp, file_name, '(');
                
                string key;
                getline(temp, key, ')');
                
                //string value=dir+"/"+file_name;
                
                //cout << key << "=" << value << endl;
                
                uom[key].push_back(dir+"/"+file_name);
                
            }
            
        }
        
        for(auto &kvp: uom) {
            //vector<string> vec=kvp.second;
            if(kvp.second.size()>1)
                ans.push_back(kvp.second);
