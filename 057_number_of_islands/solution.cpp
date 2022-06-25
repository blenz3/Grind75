class Solution {
public:
    // Strategy
    //  - Approach 1: Traverse the grid as we find 1's we DFS and repaint all 
    //                connected 1s. Continue traversing and so on with a 
    //                count of the number of DFS'
    int numIslands(vector<vector<char>>& grid) {
        int islandCount(0);
        for (size_t row = 0; row < grid.size(); ++row) {
            for (size_t col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    traverse(grid, make_pair(row, col));
                    ++islandCount;
                }
            }
        }
        
        return islandCount;
    }
    
private:
    void traverse(vector<vector<char>>& grid, pair<size_t, size_t> coord) {
        auto [row, col] = coord;
        grid[row][col] = '0';
        
        static const vector<pair<size_t, size_t>> offsets {
            { -1, 0 }, // Up
            { 1, 0 }, // Down
            { 0, -1 }, // Left
            { 0, 1 }, // Right
        };
        
        for (auto [rowOffset, colOffset] : offsets) {
            if (validCoordinate(grid, make_pair(row + rowOffset, col + colOffset))) {
                traverse(grid, make_pair(row + rowOffset, col + colOffset));
            }
        }
    }
    
    bool validCoordinate(const vector<vector<char>>&  grid, const pair<size_t, size_t>& coord) {
        auto [row, col] = coord;
        return (
            (row >= 0 && row < grid.size()) &&
            (col >= 0 && col < grid[0].size()) &&
            grid[row][col] == '1'
        );
    }
};
