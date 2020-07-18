class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> cnt{0, 0, 0};
        int res = 0;
        
        int left = 0;
        int right = 0;
        while (right < s.length()) {
            assert(s[right] >= 'a');
            assert(s[right] <= 'c');
            cnt[s[right] - 'a']++;
            while (left < right && cnt[0] && cnt[1] && cnt[2]) {
                cnt[s[left] - 'a']--;
                res += s.length() - right;
                ++left;
            }
            ++right;
        }
        return res;
    }
};