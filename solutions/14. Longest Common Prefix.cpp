class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        //const char** arr = (const char **) calloc(strs.size(), sizeof(char*));
        const char **arr = reinterpret_cast<const char **>(new char[strs.size()][sizeof(char *)]);   
        
        int arr_size=0;
        int min_row_len=INT_MAX;
        for(int i=0; i<strs.size(); i++, arr_size++) {
            arr[i] = strs[i].c_str();
            if(strs[i].length() <min_row_len)   min_row_len=strs[i].length();
        }
        
        if(min_row_len==0) return "";
        
        std::stringstream s;
        int flag=1;
        for (int j = 0; j<min_row_len; j++) {
            char ch=arr[0][j];
            //cout << ch;
            flag=1;
            for (int i = 1; i < arr_size; i++) {
                if(arr[i][j] != ch) {
                    flag=0;
                    break;
                }
            }
            if(flag==1) {
                s << ch;
                //cout << ch << "\t";
            } else break;
        }
        return s.str();
    }
};
