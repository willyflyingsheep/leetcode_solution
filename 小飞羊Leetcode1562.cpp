class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == m) {
            return n;
        }
        
        set<int> walls{0, n + 1};
        for (int step = n - 1; step > 0; --step) {
            int curr = arr[step];
            
            auto left_wall = walls.upper_bound(curr - 1);
            --left_wall;
            
            auto right_wall = walls.lower_bound(curr + 1);
            
            if (curr - *left_wall  == m + 1 ||
                *right_wall - curr == m + 1) {
                return step;
            }
            
            walls.insert(curr);
        }
        return -1;
    }
};