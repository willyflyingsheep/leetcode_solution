#define ALPHABET_LEN 26
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> c1(ALPHABET_LEN, 0);
        vector<int> c2(ALPHABET_LEN, 0);
        
        for (auto ch : s1) {
            c1[ch - 'a']++;
        }
        for (auto ch : s2) {
            c2[ch - 'a']++;
        }
        
        bool r1 = true;
        bool r2 = true;
        int count1 = 0;
        int count2 = 0;
        
        for (int i = 0 ; i < ALPHABET_LEN; ++i) {
            count1 += c1[i];
            count2 += c2[i];
            r1 &= count1 >= count2;
            r2 &= count2 >= count1;
            if (!r1 && !r2) {
                return false;
            }
        }
        
        return true;
    }
};