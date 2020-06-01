class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' ||
               c == 'e' ||
               c == 'i' ||
               c == 'o' ||
               c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int tmp = 0;
        int res = 0;
        
        int idx = 0;
        while (idx < s.length()) {
            if (isVowel(s[idx])) {
                tmp++;
            }
            
            // 类似于队列的感觉 k 
            if (idx >= k && isVowel(s[idx - k])) {
                tmp--;
            }
            
            res = max(res, tmp);
            ++idx;
        }
        
        return res;
    }
};