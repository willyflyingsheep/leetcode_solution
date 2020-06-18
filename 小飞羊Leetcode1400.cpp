class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.length()) {
            return false;
        }
        
        vector<int> counts(26);
        for (auto ch : s) {
            counts[ch - 'a']++;
        }
        
        int odds = 0;
        for (auto ct : counts) {
            odds += ct % 2;
        }
        
        return odds <= k;
    }
};