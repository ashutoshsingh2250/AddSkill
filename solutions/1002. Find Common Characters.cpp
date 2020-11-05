class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<map<char, int>> m(A.size());
        vector<string> v;
        stringstream ss;
        
        int l=0;
        for(string s:A) {
            for(int i=0; i<s.length(); i++) {
                m[l].insert({s[i],++m[l][s[i]]});
            }
            l++;
        }
        
        /*for(auto M: m) {
            for(auto it: M) {
                cout << it.first << " " << it.second << "\t";      
            }
            cout << endl<<endl;
        }*/
        
        for(int i=0; i<A[0].length(); i++) {
            char ch=A[0][i];
            //cout << ch << " ";
            bool flag=true;
            for(auto &M:m) {
                auto it=M.find(ch);     
                if(it->second>0 && it!=M.end()) {
                    flag=true;
                    it->second--;
                    /*for(auto k:M) {
                        cout << k.first << " " << k.second << "\t";
                    }*/
                    //cout << endl;
                } else {
                    flag=false; break;
                }
                //cout << endl;
