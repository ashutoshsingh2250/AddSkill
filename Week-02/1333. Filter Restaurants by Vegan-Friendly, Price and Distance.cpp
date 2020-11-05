bool compareRating(vector<int> x, vector<int> y) {
    if(x[1]==y[1])  return x[0]>y[0];
    return x[1]>y[1];
}
​
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> p; 
        if(veganFriendly==1) {
            for(int i=0; i<restaurants.size(); i++){
                if(restaurants[i][2] && restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance) {
                    p.push_back(restaurants[i]);
                }
            }
        } else {
            for(int i=0; i<restaurants.size(); i++){
                if(restaurants[i][3]<=maxPrice && restaurants[i][4]<=maxDistance) {
                    p.push_back(restaurants[i]);
                }
            }
        }  
        sort(p.begin(), p.end(), compareRating);
        vector<int> res;
        for(vector v: p) res.push_back(v[0]); 
        
        return res;
    }
};
