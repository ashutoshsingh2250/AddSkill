class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for (int i=0; i<k-1; i++) 
        { 
           pq.push(nums[i]); 
           cout << nums[i] << "_ "; 
        } 
        pq.push(nums[k-1]);
        
        for (int i=k; i<nums.size(); i++) 
        { 
            // We must insert last element before we 
            // decide last k-th largest output. 
            cout << pq.top() << " "; 
​
            if (nums[i] > pq.top()) 
            { 
                pq.pop(); 
                pq.push(nums[i]); 
            }   
        }   
        
        cout << pq.top(); 
        return pq.top();
        
    }
};
