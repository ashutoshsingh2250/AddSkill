class Solution {
public:
    int maxProfit(vector<int>& a) {
        int profit = 0, min= INT_MAX;
        for(int i=0; i<a.size(); i++) {
            if(a[i] < min)   min=a[i];
            else if(profit < a[i]-min) {
                profit=a[i]-min;
            }
        }
        return profit;
    }
};
