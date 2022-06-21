class Solution {
public:
    // Strategy
    //  - Facts
    //      - We want to flood fill all connecting values to an input pixel with the same color
    //      - These points will be distinguishable by the fact that they have the same color 
    //        as the source pixel
    //  - Strategy
    //      - DFS from the source point and overwrite the colors in place
    //      - Runtime M * N 
    //      - Space linear queue
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initialColor = image[sr][sc];
        if (color == initialColor){
            return image;
        }
        
        stack<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (!q.empty()) {
            auto [row, col] = q.top();
            q.pop();
            image[row][col] = color;
            
            // Check each direction to see if it good and the same as the source color
            static vector<pair<int, int>> offsets = {
                { 1, 0 }, // down
                { -1, 0 }, // up
                { 0, 1 }, // right
                { 0, -1 }, // left
            };
            
            for (auto [rowOffset, colOffset] : offsets) {
                auto newCoord = make_pair(row + rowOffset, col + colOffset);
                if (!cellValid(image, newCoord, initialColor)) {
                    continue;
                }
                
                q.push(newCoord);
            }   
        }
        
        return image;
    }
    
    inline bool cellValid(const vector<vector<int>>& image, pair<int, int> coord, int sourceColor) {
        auto [row, col] = coord;
        if (row < 0 || row >= image.size()) {
            return false;
        } else if (col < 0 || col >= image[0].size()) {
            return false;
        } else if (image[row][col] != sourceColor) {
            return false;
        } else {
            return true;
        }
    }
};
