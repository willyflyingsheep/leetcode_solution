class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int length = a + b + c;
        
        string res = "";
        
        /*
        0 -> a可以用的个数
        1 -> b可以用的个数
        2 -> c可以用的个数
            
        0 -> A 长度
        1 -> B
        2 -> C
        */
        
        vector<int> rb_cnt{a, b, c};
        vector<int> rb_len(3, 0);
        
        auto get_happy_ch = [&](int idx) {
            int c0 = idx % 3;
            int c1 = (idx + 1) % 3;
            int c2 = (idx + 2) % 3;
            if (  (rb_cnt[c0] >= rb_cnt[c1] && rb_cnt[c0] >= rb_cnt[c2] && rb_len[c0] != 2)
               || (rb_len[c1] == 2 && rb_cnt[c0] > 0)
               || (rb_len[c2] == 2 && rb_cnt[c0] > 0)) {
                res += 'a' + c0;
                rb_cnt[c0]--;
                rb_len[c0]++;
                rb_len[c1] = 0;
                rb_len[c2] = 0;
                return true;
            }
            return false;
        };
        
        
        for (int i = 0; i < length; ++i) {
            for (int idx = 0; idx < 3; ++idx) {
                bool found = get_happy_ch(idx);
                if (found) {
                    break;
                }
            }
        }
        
        return res;
    }
};