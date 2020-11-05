bool comparator(int a, int b) {
    string s1 = to_string(a)+to_string(b);
    string s2 = to_string(b)+to_string(a);
    return s1 > s2;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0) return "";
        sort(nums.begin(), nums.end(), comparator);
        if(nums[0]==0 && nums[nums.size()-1]==0) return "0";
        stringstream ss;
        for(int s: nums)    ss<<s;
        return ss.str();
    }
};
