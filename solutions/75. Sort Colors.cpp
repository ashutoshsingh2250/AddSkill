class Solution {
public:
    void sortColors(vector<int>& a) {
        int pivot = 1, smaller=0, larger = a.size()-1;;
        for(int i=0; i<a.size(); i++) 
            if(a[i] < pivot) swap(a[i], a[smaller++]);
        for(int i=a.size()-1; i>=0;i--) 
            if(a[i] > pivot) swap(a[i], a[larger--]);
    }
};
