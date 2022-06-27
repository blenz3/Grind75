class Solution {
public:
    // Strategy
    //   - Approach 1: Single index i compare all strs against it until one doesn't match and then end
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        
        string commonPrefix;
        
        int maxLen = maxLength(strs);
        for (int i = 0; i < maxLen; ++i) {
            char currentCharacter = '\0';
            for (auto& s : strs) {
                // This string has finished so we need to return
                if (i == s.length()) {
                    return commonPrefix;
                }
                
                // This is the first encountered character
                if (currentCharacter == '\0') {
                    currentCharacter = s[i];
                    continue;
                }    
                
                if (currentCharacter != s[i]) {
                    return commonPrefix;
                }
            }
            commonPrefix.push_back(currentCharacter);
        }
        
        return commonPrefix;
    }
    
    int maxLength(const vector<string>& strs) {
        size_t maxLen = 0;
        for (auto& s : strs) {
            maxLen = std::max(maxLen, s.length());
        }
        return maxLen;
    }
};
