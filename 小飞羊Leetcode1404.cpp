class Solution {
public:
    int numSteps(string s) {
        int res = 0;
        while (s.length() != 1) {
            // odd
            if (s.back() == '1') {
                int idx = s.length() - 1;
                while (idx >= 0 && s[idx] == '1') {
                    s[idx] = '0';
                    --idx;
                }
                if (idx < 0) {
                    s = '1' + s;   
                } else {
                    s[idx] = '1';
                }
            // even
            } else {
                s.pop_back(); // pop "0"
            }
            ++res;
        }
        return res;
    }
};