class Solution {
public:
    int minFlips(string target) {
        int res = 0;
        char curr = '0';
        for (auto & ch : target) {
            if (ch == curr) continue;
            //flip
            curr = curr == '0' ? '1' : '0';
            res++;
        }
        return res;
    }
};