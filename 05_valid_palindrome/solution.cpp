class Solution {
public:
    // Strategy
    //  - Facts
    //      - Input string only has ascii characters
    //      - Can be an empty string
    //  - Algo
    //      - Remove all unnecessary characters
    //      - Two pointers with one at start and one at end 
    //      - Check that all pointed characters are equal 
    //      - Increase start, decrease end
    //      - For odd length strings the final compare will be start == end
    //      - Runtime n / 2 == O(n)
    //      - Space linear
    bool isPalindrome(const string& s) {
        string strippedString = stripString(s);
        if (strippedString.length() <= 1)
            return true;
        
        size_t start = 0, end = strippedString.length() - 1;
        while (start <= end) {
            if (!compareCharacters(strippedString[start], strippedString[end])) {
                return false;
            }
            
            start++, end--;
        }
        
        return true;
    }
    
    string stripString(const string& s) {
        string out;
        for (auto c : s) {
            if (skippableCharacter(c)) {
                continue;
            }
            
            out.push_back(::tolower(c));
        }
        
        return out;
    }
    
    inline bool compareCharacters(const char c1, const char c2) {
        return c1 == c2;
    }
    
    inline bool skippableCharacter(const char c) {
        return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
};
