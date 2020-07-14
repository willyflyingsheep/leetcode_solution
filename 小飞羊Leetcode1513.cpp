class Solution {
public:
    int numSub(string s) {
        int k = 1e9 + 7;
        int res = 0;
        int idx = 0;
        while (idx < s.length()) {
            int j = idx;
            while (j < s.length() && s[j] == '1') {
                ++j;
            }
            
            if (idx == j) {
                ++idx;
            } else {
                res += (long)(j -  idx + 1) % k * (j - idx) % k / 2;
                res %= k;
                idx = j;
            }
        }
        return res;
    }
};