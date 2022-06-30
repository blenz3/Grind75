class MinStack {
public:
    MinStack() 
        : minSoFar(INT_MAX)
    {
        
    }
    
    void push(int val) {
        minSoFar = std::min(minSoFar, val);
        s.push({ minSoFar, val });
    }
    
    void pop() {
        s.pop();
        minSoFar = (s.empty()) ? INT_MAX : s.top().first;
    }
    
    int top() {
        return s.top().second;
    }
    
    int getMin() {
        return minSoFar;
    }
    
private:
    std::stack<std::pair<int /*minSoFar*/, int /*value*/>> s;
    int minSoFar;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
