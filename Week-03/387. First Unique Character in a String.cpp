class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++)
            if (s.find(s[i]) == s.find_last_of(s[i]))
                return i;
        return -1;
    }
};
