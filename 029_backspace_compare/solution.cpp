class Solution {
public:
    
    // Approach 2: Traverse strings and skip deleted characters without copying
    bool backspaceCompare(const string& s, const string& t) {
        int si = s.length() - 1, ti = t.length() - 1;
        while (si >= 0 && ti >= 0) {
            
            si = seek(s, si);
            ti = seek(t, ti);
            if (si < 0 != ti < 0) {
                break;
            } else if (si < 0 && ti < 0) {
                return true;
            } else if (s[si] != t[ti]) {
                return false;
            }
            --si, --ti;
        }
        
        if (si != -1) {
            si = seek(s, si);
        } else if (ti != -1) {
            ti = seek(t, ti);
        }
        
        return (si == -1 && ti == -1);
    }
    
    
    int seek(const string& s, int index) {
        // Handle edge cases
        if (index < 0) {
            return -1;
        }
        
        // Seek forward to the next not-deleted element
        int deleteCount(0);
        while (index >= 0 && (s[index] == '#' || deleteCount > 0)) {
            if (s[index] == '#') {
                deleteCount++;
            } else {
                deleteCount--;
            }
                
            index--;
        }
        
        return index;
    }
    
#if 0
    // Approach 1: Copy the strings after processing the backspaces and compare
    //  - Runtime linear
    //  - Space linear
    bool backspaceCompare(string& s, string& t) {
        return strip(s) == strip(t);
    }
    
    string strip(string& s) {
        propagateBackspaces(s);
        string out;
        for (auto c : s) {
            if (c != '#')
                out.push_back(c);
        }
        
        return out;
    }
    
    void propagateBackspaces(string& s) {
        int backspaces(0);
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '#') {
                ++backspaces;
                continue;
            }
            
            if (backspaces > 0) {
                s[i] = '#';
                --backspaces;
            }
        }
    }
#endif
};
