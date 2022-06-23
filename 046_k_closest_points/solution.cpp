
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::sort(points.begin(), points.end(), PointCompare());
        
        vector<vector<int>> out;
        for (int i = 0 ; i < k; ++i) {
            out.push_back(points[i]);
        }
        
        return out;
    }
    
private:
    

    
    struct PointCompare {
        inline bool operator()(const vector<int>& lhs, const vector<int>& rhs) {
            return euclideanDistance(lhs) < euclideanDistance(rhs);
        }  
        
        inline double euclideanDistance(const vector<int>& point) {
            return ::sqrt(
                (point[0] * point[0]) + (point[1] * point[1])
            );
        }
    };
};
