class Solution {
public:
    // Strategy
    //  - Get a count of each character  in magazine and reduce counts
    //    from ransom note. If anything is negative then false else true
    bool canConstruct(string ransomNote, string magazine) {
        std::array<int, 26> counts;
        counts.fill(0);
        
        for (char c : magazine) {
            counts[c - 'a']++;
        }
        
        for (char c : ransomNote) {
            counts[c - 'a']--;
        }
        
        for (auto count : counts) {
            if (count < 0) {
                return false;
            }
        }
        
        return true;
    }
};
