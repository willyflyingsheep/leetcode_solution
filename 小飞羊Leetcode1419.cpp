class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        
        int frog = 0;
        int res = 0;
        
        for (auto & ch : croakOfFrogs) {
            if (ch == 'c') {
                ++c;
                ++frog;
            } else if (ch == 'r') {
                ++r;
            } else if (ch == 'o') {
                ++o;
            } else if (ch == 'a') {
                ++a;
            } else if (ch == 'k') {
                ++k;
                --frog;
            }            
            res = max(res, frog);
            if (c >= r && r >= o && o >= a && a >= k) {
                continue;
            } else {
                return -1;
            }
        }
        
        if (c != r || r != o || o != a || a != k) {
            return -1;
        }
        return res;
    }
};