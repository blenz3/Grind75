// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // Strategy
    //  - Binary search the input set for bad versions
    int firstBadVersion(int n) {
        int64_t minBadVersion = n;
        int64_t start = 0, end = n;
        while (start <= end) {
            int64_t mid = (start + end) / 2;
            bool isBad = isBadVersion(mid);
            if (isBad) {
                minBadVersion = std::min(minBadVersion, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return minBadVersion;
    }
};
