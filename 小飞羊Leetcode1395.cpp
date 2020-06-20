class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        int length = rating.size();
        for (int m = 1; m <= length - 2; ++m) {
            int left_asc = 0;
            int left_dec = 0;
            int right_asc = 0;
            int right_dec = 0;
            for (int l = 0; l < m; ++l) {
                if (rating[l] < rating[m]) left_asc++;
                else if (rating[l] > rating[m]) left_dec++;
            }
            for (int r = m + 1; r < length; ++r) {
                if (rating[m] < rating[r]) right_asc++;
                else if (rating[m] > rating[r]) right_dec++;
            }
            
            res += left_asc * right_asc + left_dec * right_dec;
        }
        return res;
    }
};