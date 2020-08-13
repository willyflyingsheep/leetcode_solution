class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> has_shifted(26);
        for (int i = 0; i < s.length(); ++i) {
            int shift = (t[i] + 26 - s[i]) % 26;
            if (shift != 0 && shift + 26 * has_shifted[shift] > k) {
                return false;
            } else {
                has_shifted[shift]++;
            }
            
        }
        return true;
    }
};