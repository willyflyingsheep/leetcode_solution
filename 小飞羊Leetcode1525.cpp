class Solution {
public:
    int numSplits(string s) {
        if (s.length() == 1) {
            return 0;
        }

        unordered_map<char, int> left;
        unordered_map<char, int> right;
        left.reserve(26);
        right.reserve(26);
        
        for (auto & ch : s) {
            right[ch]++;
        }
        
        int res = 0;
        for (auto & ch : s) {
            left[ch]++;
            right[ch]--;
            if (right[ch] == 0) right.erase(ch);
            res += left.size() == right.size() ? 1 : 0;
        }
        return res;
    }
};