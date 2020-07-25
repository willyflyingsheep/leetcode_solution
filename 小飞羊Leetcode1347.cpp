class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26);
        assert(s.length() == t.length());
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i] -'a']++;
            freq[t[i] -'a']--;
        }
        
        int res = 0;
        for (auto dist : freq) {
            res += dist > 0 ? dist : 0;
        }
        return res;
    }
};