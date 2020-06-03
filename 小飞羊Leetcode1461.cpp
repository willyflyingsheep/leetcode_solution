class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n - k + 1 < pow(2, k)) {
            return false;
        }
        unordered_set<string> set;
        for (int i = 0; i <= n - k; ++i) {
            set.insert(s.substr(i, k));
        }
        return set.size() == pow(2, k);
    }
};