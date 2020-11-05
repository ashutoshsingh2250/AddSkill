class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
        vector<vector<int>> row(a.size(), vector<int>(a.size(), 0));
        vector<vector<int>> col(a.size(), vector<int>(a.size(), 0));
        vector<vector<int>> box(a.size(), vector<int>(a.size(), 0));
        
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                
                char ch=a[i][j];
                if(ch != '.') {
                    
                    int key=-1;
                    string skey=string(1, ch); 
                    key=stoi(skey)-1;
                    //cout << key << " ";
​
                    if(!row[i][key])
                        ++row[i][key];
                    else return false;
​
                    if(!col[j][key])
                        ++col[j][key];
                    else return false;
​
                    int box_index=(i / 3 ) * 3 + j / 3;
                    if(!box[box_index][key])
                        ++box[box_index][key];
                    else return false;    
​
                }
         
            }
            //cout << endl;
        }
        return true;
    }
};
