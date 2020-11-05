// Solution 1
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it=nums.begin(); it!=nums.end(); it++) {
            if(s.find(*it) != s.end())
            {    //std::remove(it, it, *it);
                nums.erase(it);
                it--;
            }
            else {
                s.insert(*it);
            }
        }
        return nums.size();
    }
};*/
​
// Solution 2
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
​
        int len=0;
        auto it=nums.begin();
        while (it!=nums.end()) {
            int count=0;
            int val=*it;
            while (val==*it) {
                count++;
                if(it != nums.end())
                    it++;
            }
            len++;
            nums.erase(it-count+1,it);
            //remove(it-count, it-1, val);
            if(it!=nums.begin()) it--;
            count=0;
