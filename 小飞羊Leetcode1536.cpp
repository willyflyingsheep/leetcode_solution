class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        assert(rows == cols);
        
        // count each row's tail zeros
        vector<int> tail_zeros(rows);
        for (int r = 0; r < rows; ++r) {
            int tail_zero_num = 0;
            for (int c = cols - 1; c >= 0; --c) {
                if (grid[r][c]) {
                    break;
                }
                tail_zero_num++;
            }
            tail_zeros[r] = tail_zero_num;
        }
        
        
        int res = 0;
        for (int r = 0; r < rows; ++r) {
            int need_zeros = cols - 1 - r;
            int idx = r;
            while (idx < rows && tail_zeros[idx] < need_zeros) {
                ++idx;
            }
            
            if (idx == rows) return -1;
            
            res += idx - r;
            
            while (idx != r) {
                tail_zeros[idx] = tail_zeros[idx - 1];
                idx--;
            }
        }
        return res;
    }
};