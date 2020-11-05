class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!s2.empty()) {
            int v = s2.top();
            s2.pop();
            return v;
        }
        else if(!s1.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            int v = s2.top();
            s2.pop();
            return v;
        }
        else return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if(!s2.empty()) {
            int v = s2.top();
            return v;
        }
