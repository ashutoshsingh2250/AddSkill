class Solution {
public:
    char toChar(int i) {
        return char(i);
    }
    bool isPalindrome(string s) {
​
        if(s.empty()) return true;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n=s.length();
        const char *a= const_cast<char*>(s.c_str());
        char *r = new char[n+1];
        memset(r, '\0', n+1);
        
        int r_len=0;
        for(int i=0; a[i]!='\0'; i++) {
            if(a[i] >= 'a' && a[i] <='z' || a[i]>='0' && a[i]<='9') {
                r[r_len] = a[i];
                r_len++;
            }
        }
​
        for(int i=0; i<=ceil(r_len/2)-1; i++) {
            if(r[i] != r[r_len-i-1]) {
                return false;
            }
        }
        return true;
    }
};
​
​
​
​
​
​
​
​
