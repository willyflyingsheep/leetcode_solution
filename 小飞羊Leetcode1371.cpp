class Solution {
public:
    int findTheLongestSubstring(string s) {
        // a, e, i, o, u
        // 0  0  0  0  0
        unordered_map<char, int> vowels;
        vowels['a'] = 4;
        vowels['e'] = 3;
        vowels['i'] = 2;
        vowels['o'] = 1;
        vowels['u'] = 0;
        
        vector<int> patterns(32, -1);
        int res = 0;
        int mask = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (vowels.count(s[i])) {
                mask ^= 1 << vowels[s[i]];
            }
            if (patterns[mask] == -1 && mask) {
                patterns[mask] = i;
            } else {
                res = max(res, i - patterns[mask]);
            }
        }
        return res;
        
    }
};