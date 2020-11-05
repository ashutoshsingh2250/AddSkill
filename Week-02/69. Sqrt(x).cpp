class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1) return x;
        int i=0;
        double ans=1.0;
        
        while(ans <= x) {
            i++;
            ans=i*1.0;
            ans*=ans;
        }
        
        return i-1;
    }
};
​
​
/*int mySqrt(int x) {
    double low = 0.0, high = x;
    int iter = 100;
    for(int i = 0 ; i < iter ; ++i){
        double mid = (low + high) / 2.0;
        if(mid * mid <= x){
            low = mid;
        } else{
            high = mid;
        }
    }
    return low;
}*/
