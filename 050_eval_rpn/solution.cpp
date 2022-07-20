class Solution {
public:
    // Approach 1: Use a stack and enqueue elements until we hit an operator at which point we pop
    // two elements and enqueue the result
    int evalRPN(const vector<string>& tokens) {
        stack<int64_t> values;
        auto getNextValue = [&values]() {
            auto val = values.top();
            values.pop();
            return val;
        };
        
        for (auto token : tokens) {
            if (!isOperator(token)) {
                values.push(std::stoll(token));
                continue;
            }
            
            auto rhs = getNextValue();
            auto lhs = getNextValue();
            auto result = evaluate(token[0], lhs, rhs);
            values.push(result); 
        }

        return values.top();
    }
    
    bool isOperator(const std::string& s) {
        if (s.length() > 1) {
            return false;
        }
        char c = s[0];
        return (c == '+' || c == '-' || c == '/' || c == '*');
    }
    
    int64_t evaluate(char op, int64_t lhs, int64_t rhs) {
        switch (op) {
            case '+':
                return lhs + rhs;
            case '-':
                return lhs - rhs;
            case '*':
                return lhs * rhs;
            case '/':
                return lhs / rhs;
            default:
                throw std::runtime_error("ERROR: Invalid operator received!");
        }
    }
};
