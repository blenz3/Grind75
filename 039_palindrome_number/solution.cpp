class Solution {
public:
    // Strategy
    //  - Approach 1: Convert to string, copy, reverse copy, compare
    //  - Approach 2: Pop digits into a vector and then compare for palindrome
    //  - Approach 3: Reverse number and then compare with original
    bool isPalindrome(int64_t x) {
        if (x < 0) 
            return false;
        
        int64_t reversed = reverseNumber(x);
        // printf("x = %d rev = %d\n", x, reversed);
        while (reversed != 0 && x != 0) {
            int64_t reversedDigit = reversed % 10;
            int64_t xDigit = x % 10;
            
            if (reversedDigit != xDigit) {
                return false;
            }
            
            reversed /= 10;
            x /= 10;
        }
        
        return true;
    }
    
    int64_t reverseNumber(int64_t x) {
        int64_t out = 0;
        while (x != 0) {
            out *= 10;
            out += (x % 10);
            x /= 10;
        }
        return out;
    }
};
