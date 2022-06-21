class Solution {
public:
    // Strategy
    //  - Facts
    //      - String only consists of (), {}, []
    //      - Opens must be matched by a close to be valid
    //  - Strategy
    //      - Stack based strategy where we push open parens and upon a close we pop the top
    //      - If the top is mismatched then it's not valid
    //      - Runtime linear
    //      - Space linear
    bool isValid(const string& s) {
        stack<char> opens;
        for (auto c : s) {
            if (isOpen(c)) {
                opens.push(c);
                continue;
            } 
            
            // There is no corresponding open because the stack has been drained
            if (opens.empty()) {
                return false;
            }
            
            // This open close pair doesn't match
            auto top = opens.top();
            if (!isMatch(top, c)) {
                return false;
            }
            
            // Pop the stack 
            opens.pop();
        }
        
        return opens.empty();
    }
    
    inline bool isOpen(const char c) {
        return (c == '(' || c == '{' || c == '[');
    }
    
    inline bool isClose(const char c) {
        return !isOpen(c);
    }

    inline bool isMatch(const char c1, const char c2) {
        // This could never be a parens closure
        if (isClose(c1) || isOpen(c2)) {
            return false;
        }
        
        switch(c1) {
            case '(':
                return c2 == ')';
            case '{':
                return c2 == '}';
            case '[':
                return c2 == ']';
            default:
                return false;
        }
    }
};
