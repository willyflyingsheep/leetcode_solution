class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> l(26, INT_MAX);
        vector<int> r(26, INT_MIN);
        for (int i = 0; i < s.length(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        
        vector<string> res;
        int pos = -1;
        for (int idx = 0; idx < s.length(); ++idx) {
            if (idx == l[s[idx] - 'a']) {
                
                int left = l[s[idx] - 'a'];
                int right = r[s[idx] - 'a'];
                while (left < right && l[s[left] - 'a'] >= idx) {
                    right = max(right, r[s[left] - 'a']);
                    ++left;
                }
                
                if (left < right && l[s[left] - 'a'] < idx) {
                    continue;
                }
                
                
                if (pos < idx) {
                    res.push_back("");
                }
                pos = right;
                res.back() = s.substr(idx, pos - idx + 1);
            }
        }
        
        return res;
    }
};