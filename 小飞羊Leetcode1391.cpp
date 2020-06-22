class Solution {
private:
    bool isConnected(vector<vector<int>>& direct, int prev_street_type, int y_, int x_) {
        int street = prev_street_type * 2;
        for (int i = 0; i < 2; ++i) {
            int y_pos = direct[street + i][0];
            int x_pos = direct[street + i][1];
            if (y_pos == y_ && x_pos == x_) {
                return true;
            }
        }
        return false;
        
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        // 1 <= r, c <= 300
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> direct{
            {0, -1}, {0,  1}, // street 1
            {-1, 0}, {1,  0}, // street 2
            {0, -1}, {1,  0}, // street 3
            {0,  1}, {1,  0}, // ...
            {0, -1}, {-1, 0},
            {0,  1}, {-1, 0}
        };
        
        queue<int> q;
        unordered_set<int> visited;
        q.push(0);
        visited.insert(0);
        
        while (!q.empty()) {
            int next = q.front();
            q.pop();
            int y = next / c;
            int x = next % c;
            if (y == r - 1 && x == c - 1) {
                return true;
            }
            int val = grid[y][x] - 1;
            int street = val * 2;
            for (int i = 0; i < 2; ++i) {
                int dy = y + direct[street + i][0];
                int dx = x + direct[street + i][1];
                if (dy >= 0 && dy < r && dx >= 0 && dx < c &&
                    !visited.count(dy * c + dx) && 
                    isConnected(direct, grid[dy][dx] - 1, 
                                -direct[street + i][0], 
                                -direct[street + i][1])) {
                    visited.insert(dy * c + dx);
                    q.push(dy * c + dx);
                }
            }
        }
        
        return false;
        
    }
};