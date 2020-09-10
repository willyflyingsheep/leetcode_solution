class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int cp = 0;
        int cn = 0;
        int res = 0;
        for (auto num : nums) {
            if (num == 0) {
                cp = 0;
                cn = 0;
            } else if (num > 0) {
                cp += 1;
                cn = cn > 0 ? cn + 1 : 0;
            } else {
                int tmp = cp;
                cp = cn > 0 ? cn + 1 : 0;
                cn = tmp + 1;
            }
            res = max(res, cp);
        }
        return res;
    }
};