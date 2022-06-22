class MyQueue {
public:
    // Strategy
    //  - Facts
    //      - We can only use stacks to make a queue
    //      - stacks are LIFO only suppose push, pop, top
    //  - Algo
    //      - We can maintain some state to determine if we are currently a stack or a queue
    //      - We can use  two stacks to simulate a queue by pushing everything from one stack into 
    //        a secondary stack
    MyQueue()
        : isStack(true)
    {
        
    }
    
    void push(int x) {
        if (!isStack) {
            swap();
        }
        
        getStack().push(x);
    }
    
    int pop() {
        if (isStack) {
            swap();
        }
        
        auto& stack = getStack();
        int val = stack.top();
        stack.pop();
        return val;
    }
    
    int peek() {
        if (isStack) {
            swap();
        }
        
        return getStack().top();
    }
    
    bool empty() {
        return getStack().empty();
    }
    
private:
    bool isStack;
    stack<int> q1, q2;
    
    stack<int>& getStack() {
        return (!q1.empty()) ? q1 : q2;
    }
    
    stack<int>& getEmptyStack() {
        return (q1.empty()) ? q1 : q2;
    }
    
    void swap() {
        auto& fullStack = getStack();
        auto& emptyStack = getEmptyStack();
        
        
        isStack = !isStack;
        
        while (!fullStack.empty()) {
            auto top = fullStack.top();
            emptyStack.push(top);
            fullStack.pop();
        }
        
        
    }
   
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
