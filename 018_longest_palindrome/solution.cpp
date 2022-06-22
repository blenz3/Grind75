class Solution {
public:
    // Strategy
    //  - Facts
    //      - We can rearrange the string anyway we like
    //      - a palindrome is that which is the same front to back as back to front
    //      - case sensitive
    //  - Algo
    //      - Get the counts for all characters
    //      - include all characters that have an even count
    //      - include at most one character with an odd count
    int longestPalindrome(const string& s) {
        std::array<int, 256> counts;
        counts.fill(0);
        for (auto c : s) {
            counts[static_cast<size_t>(c)]++;
        }
        
        // For each count grab as an even number of characters and 
        // one odd character from somewhere in the list
        int oddCount(0), evenCount(0);
        for (auto count : counts) {
            if (count % 2 == 0) {
                evenCount += count;
            } else if (oddCount == 0) {
                oddCount = 1;
                evenCount += count - 1;
            } else if (count >= 1) {
                evenCount += count - 1;
            }
        }
        
        return evenCount + oddCount; 
    }
};
