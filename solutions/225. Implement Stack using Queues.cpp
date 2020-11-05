class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty() && q2.empty()) q1.push(x);
        else if(!q1.empty() && q2.empty())    q1.push(x);
        else if(!q2.empty() && q1.empty())    q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty() && q2.empty())    return -1;
        else if(!q1.empty() && q2.empty()) {
            while(q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int v=q1.back();
            q1.pop();
            return v;
        }
        else if(!q2.empty() && q1.empty()) {
            while(q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int v=q2.back();
            q2.pop();
            return v;
        }
        return -1;
    }
