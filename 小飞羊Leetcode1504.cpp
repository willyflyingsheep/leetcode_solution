class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int r = mat.size();
        if (r == 0) return 0;
        int c = mat[0].size();
        if (c == 0) return 0;
        
        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
        
        int res = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (mat[i - 1][j - 1]) {
                    dp[i][j] = dp[i][j - 1] + 1;
                    res += dp[i][j];
                    int min_ones = dp[i][j];
                    for (int k = i - 1; k >= 0; --k) {
                        min_ones = min(min_ones, dp[k][j]);
                        res += min_ones;
                    }
                }
            }
        }
        
        return res;
    }
};