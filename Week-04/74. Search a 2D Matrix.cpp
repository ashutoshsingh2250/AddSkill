class Solution {
    
    bool BS(vector<vector<int>>& a, int l, int h, int key) {
        cout << endl;
        if(l>h) return false;
        else if(l<=h) {
            
            int m = (l+h)/2;
            //cout << "mid=" << m << endl;
            
            int n=a[0].size();
            //cout << "n=" << n << endl;
            
            int row=m/n; int col=m%n;
            //cout << "row=" << row << " col=" << col << endl;
            
            int num=a[row][col];
            //cout << "a[mid]=" << num << endl;
​
            if(num==key) return true;
            else if(key<num)    return BS(a, l, m-1, key);
            else if(key>num)    return BS(a, m+1, h, key);
        }
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& a, int key) {
        if(a.size()==0) return false;
        
        bool ans=BS(a, 0, (a.size()*a[0].size())-1, key);
        
        return ans;
    }
};
