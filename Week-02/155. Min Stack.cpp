class MinStack {
    stack<long>s;
    long m;
public:
    MinStack():m{INT_MAX} {}
​
    void push(int x) {
        if(s.empty())
        {
            s.push(0);
            m=x;
        }
        else
        {
            s.push(x-m);
            if(s.top()<0)
            {
                m=x;
            }
        }
    }
​
    void pop() {
        if(s.top()<0)
        {
            m=m-s.top();
            s.pop();
        }
        else 
            s.pop();
    }
​
    int top() {
        if(s.top()<0) 
            return m;
        else 
            return m+s.top();
    }
​
