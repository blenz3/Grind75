class Solution {
public:
    // Strategy
    //  - Facts
    //      - Inputs are all lowercase ascii characters
    //      - Lengths might be equal?
    //  - Algo
    //      - Get character counts of each and compare the counts
    //      - Runtime 2n == O(n)
    //      - Space 2*26 == O(1)
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        std::array<int, 26> sCount, tCount;
        countCharacters(s, sCount);
        countCharacters(t, tCount);
        
        return compareCounts(sCount, tCount);
    }
    
    void countCharacters(const string& s, std::array<int, 26>& characters) {
        characters.fill(0);
        for (auto c : s) {
            characters[c - 'a']++;
        }
    }
    
    bool compareCounts(const std::array<int, 26>& count1, const std::array<int, 26>& count2) {
        for (size_t i = 0; i < count1.size(); ++i) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        
        return true;
    }
};
