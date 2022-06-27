class Solution {
public:
    // Approach 1: Accumulate all start end times in an ordered map and see if there are overlaps
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) {
            return true;
        }
        
        std::map<int, int> counts;
        for (auto& meeting : intervals) {
            counts[meeting.front()]++;
            counts[meeting.back()]--;
        }
        
        // Traverse all meetings and see if we ever end up with more than one at once
        int requiredMeetings(0);
        for (auto& kvp : counts) {
            requiredMeetings += kvp.second;
            if (requiredMeetings > 1) {
                return false;
            }
        }
        
        return true;
    }
};
